#include "STM8L052C6.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define UART_BUFFER_SIZE 32

#define MP1 (1 << 2)

#define MOTO_E7 (1 << 7)
#define MOTO_E6 (1 << 6)
#define SEN_C3 (1 << 3)
#define MOTO_C4 (1 << 4)
#define MOTO_C7 (1 << 7)


uint8_t count = 0, uartBufferPos = 0;
char uartBuffer[UART_BUFFER_SIZE];
bool dir = false;


void delay(uint32_t ms){
    uint32_t ticks = ms*600/(1 << CLK_CKDIVR);
    uint32_t d;
    for(d = 0; d < ticks; d++) { }
}


void initMotor() {
        // 1. H-Bridge
    PE_DDR |= MOTO_E7 | MOTO_E6;
    PE_CR1 |= MOTO_E7 | MOTO_E6;
    PE_ODR |= MOTO_E7 | MOTO_E6;

        // 2. H-Bridge
    PC_DDR |= MOTO_C4 | MOTO_C7;
    PC_CR1 |= MOTO_C4 | MOTO_C7;
    PC_ODR |= MOTO_C4 | MOTO_C7;

}

void setMotor(bool st1, bool st2) {
    if (st1) {
        PE_ODR &= ~MOTO_E7 & ~MOTO_E6; // 3.3V
    } else {
        PE_ODR |= MOTO_E7 | MOTO_E6; // 0V
    }
    if (st2) {
        PC_ODR &= ~MOTO_C4 & ~MOTO_C7; // 3.3V
    } else {
        PC_ODR |= MOTO_C4 | MOTO_C7; // 0V
    }

}


void initUSART() {
    SYSCFG_RMPCR1 |= 0x10; // TX: PA2, RX: PA3
    PA_DDR |= MP1;
    PA_CR1 |= MP1;

    USART1_CR2 = USART_CR2_TEN | USART_CR2_REN | USART_CR2_RIEN; // Transmit, receive, interrrupt enable
    USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
    USART1_BRR1 = 0x11; USART1_BRR2 = 0x6; // 57600 baud (use 8 B for 115200)
}

int uartWrite(const char *str) {
	char i;
	for(i = 0; i < strlen(str); i++) {
		while(!(USART1_SR & USART_SR_TXE));
		USART1_DR = str[i];
	}
	return(i); // Bytes sent
}

void putchar(unsigned char data) {
    USART1_DR = data;
    while (!(USART1_SR & USART_SR_TC));
}

char uartRead() {
    if(USART1_SR & USART_SR_RXNE) {
        return USART1_DR;
    } else {
        return '\0';
    }
}

char* readUartBuffer() {
    uartBufferPos = 0;
    return uartBuffer;
}

void clearUartBuffer() {
    memset(uartBuffer,0,UART_BUFFER_SIZE);
}


void initADC() {
    ADC1_SQR1 |= ADC1_SQR1_DMAOFF; // disable DMA
    ADC1_SQR4 |= (1 << 5); // Select ADC 5 (PC3)
    ADC1_CR1 |= ADC1_CR1_ADON; // wake up
    // ADC1_CR1 &= ~ADC1_CR1_ADON; // off
}

uint16_t readADC() {
    uint8_t adcH, adcL;
    ADC1_CR1 |= ADC1_CR1_START; // start
    while (!(ADC1_SR & ADC1_SR_EOC));
    adcH = ADC1_DRH;
    adcL = ADC1_DRL;
    //ADC1_CSR &= ~(1 << ADC1_CSR_EOC); // Clear EOC flag
    return (adcL | (adcH << 8));
}


void initClock() {
    CLK_CKDIVR = 0; // Set the frequency to 16 MHz
    CLK_PCKENR1 = 0xFF; // Enable peripherals
    CLK_PCKENR2 = 0xFF;
}


int main() {
        initClock();

        enableInterrupts()

        initADC();

        initUSART();

        initMotor();

        printf("Thermostat: Startup complete\n");

        while(true) {
            uint16_t adc;

            delay(100);

            adc = readADC();
            printf("ADC value: %d, %d\n", readADC(), uartBufferPos);

            if (count > 0) {
              setMotor(dir, !dir);
              count--;
            } else {
              setMotor(0, 0);
            }
        }
    }

    #define UART_RECV_ISR 28

    void uart_isr() __interrupt(UART_RECV_ISR) {
        uint8_t i;
        uartBufferPos %= UART_BUFFER_SIZE-1;
        for(i = uartBufferPos; i < UART_BUFFER_SIZE; i++) {
            uartBuffer[i] = uartRead();
        }
        uartBufferPos++;
    }
