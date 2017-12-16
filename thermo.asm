;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (Linux)
;--------------------------------------------------------
	.module thermo
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _uart_isr
	.globl _main
	.globl _initClock
	.globl _readADC
	.globl _initADC
	.globl _clearUartBuffer
	.globl _readUartBuffer
	.globl _uartRead
	.globl _uartWrite
	.globl _initUSART
	.globl _setMotor
	.globl _initMotor
	.globl _delay
	.globl _printf
	.globl _strlen
	.globl _memset
	.globl _dir
	.globl _uartBufferPos
	.globl _count
	.globl _uartBuffer
	.globl _putchar
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
_uartBuffer::
	.ds 32
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
_count::
	.ds 1
_uartBufferPos::
	.ds 1
_dir::
	.ds 1
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ;reset
	int 0x0000 ;trap
	int 0x0000 ;int0
	int 0x0000 ;int1
	int 0x0000 ;int2
	int 0x0000 ;int3
	int 0x0000 ;int4
	int 0x0000 ;int5
	int 0x0000 ;int6
	int 0x0000 ;int7
	int 0x0000 ;int8
	int 0x0000 ;int9
	int 0x0000 ;int10
	int 0x0000 ;int11
	int 0x0000 ;int12
	int 0x0000 ;int13
	int 0x0000 ;int14
	int 0x0000 ;int15
	int 0x0000 ;int16
	int 0x0000 ;int17
	int 0x0000 ;int18
	int 0x0000 ;int19
	int 0x0000 ;int20
	int 0x0000 ;int21
	int 0x0000 ;int22
	int 0x0000 ;int23
	int 0x0000 ;int24
	int 0x0000 ;int25
	int 0x0000 ;int26
	int 0x0000 ;int27
	int _uart_isr ;int28
	int 0x0000 ;int29
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	thermo.c: 24: void delay(uint32_t ms){
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	sub	sp, #12
;	thermo.c: 25: uint32_t ticks = ms*600/(1 << CLK_CKDIVR);
	ldw	x, (0x11, sp)
	pushw	x
	ldw	x, (0x11, sp)
	pushw	x
	push	#0x58
	push	#0x02
	clrw	x
	pushw	x
	call	__mullong
	addw	sp, #8
	ldw	(0x0b, sp), x
	ldw	(0x09, sp), y
	ldw	x, #0x50c0
	ld	a, (x)
	ldw	x, #0x0001
	tnz	a
	jreq	00117$
00116$:
	sllw	x
	dec	a
	jrne	00116$
00117$:
	clrw	y
	tnzw	x
	jrpl	00118$
	decw	y
00118$:
	pushw	x
	pushw	y
	ldw	x, (0x0f, sp)
	pushw	x
	ldw	x, (0x0f, sp)
	pushw	x
	call	__divulong
	addw	sp, #8
	ldw	(0x07, sp), x
	ldw	(0x05, sp), y
;	thermo.c: 27: for(d = 0; d < ticks; d++) { }
	clrw	x
	ldw	(0x03, sp), x
	ldw	(0x01, sp), x
00103$:
	ldw	x, (0x03, sp)
	cpw	x, (0x07, sp)
	ld	a, (0x02, sp)
	sbc	a, (0x06, sp)
	ld	a, (0x01, sp)
	sbc	a, (0x05, sp)
	jrnc	00105$
	ldw	x, (0x03, sp)
	addw	x, #0x0001
	ldw	(0x03, sp), x
	ld	a, (0x02, sp)
	adc	a, #0x00
	ld	(0x02, sp), a
	ld	a, (0x01, sp)
	adc	a, #0x00
	ld	(0x01, sp), a
	jra	00103$
00105$:
	addw	sp, #12
	ret
;	thermo.c: 31: void initMotor() {
;	-----------------------------------------
;	 function initMotor
;	-----------------------------------------
_initMotor:
;	thermo.c: 33: PE_DDR |= MOTO_E7 | MOTO_E6;
	ldw	x, #0x5016
	ld	a, (x)
	or	a, #0xc0
	ld	(x), a
;	thermo.c: 34: PE_CR1 |= MOTO_E7 | MOTO_E6;
	ldw	x, #0x5017
	ld	a, (x)
	or	a, #0xc0
	ld	(x), a
;	thermo.c: 35: PE_ODR |= MOTO_E7 | MOTO_E6;
	ldw	x, #0x5014
	ld	a, (x)
	or	a, #0xc0
	ld	(x), a
;	thermo.c: 38: PC_DDR |= MOTO_C4 | MOTO_C7;
	ldw	x, #0x500c
	ld	a, (x)
	or	a, #0x90
	ld	(x), a
;	thermo.c: 39: PC_CR1 |= MOTO_C4 | MOTO_C7;
	ldw	x, #0x500d
	ld	a, (x)
	or	a, #0x90
	ld	(x), a
;	thermo.c: 40: PC_ODR |= MOTO_C4 | MOTO_C7;
	ldw	x, #0x500a
	ld	a, (x)
	or	a, #0x90
	ld	(x), a
	ret
;	thermo.c: 44: void setMotor(bool st1, bool st2) {
;	-----------------------------------------
;	 function setMotor
;	-----------------------------------------
_setMotor:
;	thermo.c: 45: if (st1) {
	tnz	(0x03, sp)
	jreq	00102$
;	thermo.c: 46: PE_ODR &= ~MOTO_E7 & ~MOTO_E6; // 3.3V
	ldw	x, #0x5014
	ld	a, (x)
	and	a, #0x3f
	ld	(x), a
	jra	00103$
00102$:
;	thermo.c: 48: PE_ODR |= MOTO_E7 | MOTO_E6; // 0V
	ldw	x, #0x5014
	ld	a, (x)
	or	a, #0xc0
	ld	(x), a
00103$:
;	thermo.c: 50: if (st2) {
	tnz	(0x04, sp)
	jreq	00105$
;	thermo.c: 51: PC_ODR &= ~MOTO_C4 & ~MOTO_C7; // 3.3V
	ldw	x, #0x500a
	ld	a, (x)
	and	a, #0x6f
	ld	(x), a
	ret
00105$:
;	thermo.c: 53: PC_ODR |= MOTO_C4 | MOTO_C7; // 0V
	ldw	x, #0x500a
	ld	a, (x)
	or	a, #0x90
	ld	(x), a
	ret
;	thermo.c: 59: void initUSART() {
;	-----------------------------------------
;	 function initUSART
;	-----------------------------------------
_initUSART:
;	thermo.c: 60: SYSCFG_RMPCR1 |= 0x10; // TX: PA2, RX: PA3
	ldw	x, #0x509e
	ld	a, (x)
	or	a, #0x10
	ld	(x), a
;	thermo.c: 61: PA_DDR |= MP1;
	ldw	x, #0x5002
	ld	a, (x)
	or	a, #0x04
	ld	(x), a
;	thermo.c: 62: PA_CR1 |= MP1;
	ldw	x, #0x5003
	ld	a, (x)
	or	a, #0x04
	ld	(x), a
;	thermo.c: 64: USART1_CR2 = USART_CR2_TEN | USART_CR2_REN | USART_CR2_RIEN; // Transmit, receive, interrrupt enable
	mov	0x5235+0, #0x2c
;	thermo.c: 65: USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xcf
	ld	(x), a
;	thermo.c: 66: USART1_BRR1 = 0x11; USART1_BRR2 = 0x6; // 57600 baud (use 8 B for 115200)
	mov	0x5232+0, #0x11
	mov	0x5233+0, #0x06
	ret
;	thermo.c: 69: int uartWrite(const char *str) {
;	-----------------------------------------
;	 function uartWrite
;	-----------------------------------------
_uartWrite:
	sub	sp, #3
;	thermo.c: 71: for(i = 0; i < strlen(str); i++) {
	clr	(0x01, sp)
00106$:
	ldw	x, (0x06, sp)
	pushw	x
	call	_strlen
	addw	sp, #2
	ldw	(0x02, sp), x
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	cpw	x, (0x02, sp)
	jrnc	00104$
;	thermo.c: 72: while(!(USART1_SR & USART_SR_TXE));
00101$:
	ldw	x, #0x5230
	ld	a, (x)
	tnz	a
	jrpl	00101$
;	thermo.c: 73: USART1_DR = str[i];
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	x, (0x06, sp)
	ld	a, (x)
	ldw	x, #0x5231
	ld	(x), a
;	thermo.c: 71: for(i = 0; i < strlen(str); i++) {
	inc	(0x01, sp)
	jra	00106$
00104$:
;	thermo.c: 75: return(i); // Bytes sent
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	sp, #3
	ret
;	thermo.c: 78: void putchar(unsigned char data) {
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
;	thermo.c: 79: USART1_DR = data;
	ldw	x, #0x5231
	ld	a, (0x03, sp)
	ld	(x), a
;	thermo.c: 80: while (!(USART1_SR & USART_SR_TC));
00101$:
	ldw	x, #0x5230
	ld	a, (x)
	bcp	a, #0x40
	jreq	00101$
	ret
;	thermo.c: 83: char uartRead() {
;	-----------------------------------------
;	 function uartRead
;	-----------------------------------------
_uartRead:
;	thermo.c: 84: if(USART1_SR & USART_SR_RXNE) {
	ldw	x, #0x5230
	ld	a, (x)
	bcp	a, #0x20
	jreq	00102$
;	thermo.c: 85: return USART1_DR;
	ldw	x, #0x5231
	ld	a, (x)
	ret
00102$:
;	thermo.c: 87: return '\0';
	clr	a
	ret
;	thermo.c: 91: char* readUartBuffer() {
;	-----------------------------------------
;	 function readUartBuffer
;	-----------------------------------------
_readUartBuffer:
;	thermo.c: 92: uartBufferPos = 0;
	clr	_uartBufferPos+0
;	thermo.c: 93: return uartBuffer;
	ldw	x, #_uartBuffer+0
	ret
;	thermo.c: 96: void clearUartBuffer() {
;	-----------------------------------------
;	 function clearUartBuffer
;	-----------------------------------------
_clearUartBuffer:
;	thermo.c: 97: memset(uartBuffer,0,UART_BUFFER_SIZE);
	ldw	x, #_uartBuffer+0
	push	#0x20
	push	#0x00
	push	#0x00
	push	#0x00
	pushw	x
	call	_memset
	addw	sp, #6
	ret
;	thermo.c: 101: void initADC() {
;	-----------------------------------------
;	 function initADC
;	-----------------------------------------
_initADC:
;	thermo.c: 102: ADC1_SQR1 |= ADC1_SQR1_DMAOFF; // disable DMA
	bset	0x534a, #7
;	thermo.c: 103: ADC1_SQR4 |= (1 << 5); // Select ADC 5 (PC3)
	ldw	x, #0x534d
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
;	thermo.c: 104: ADC1_CR1 |= ADC1_CR1_ADON; // wake up
	bset	0x5340, #0
	ret
;	thermo.c: 108: uint16_t readADC() {
;	-----------------------------------------
;	 function readADC
;	-----------------------------------------
_readADC:
	sub	sp, #6
;	thermo.c: 110: ADC1_CR1 |= ADC1_CR1_START; // start
	ldw	x, #0x5340
	ld	a, (x)
	or	a, #0x02
	ld	(x), a
;	thermo.c: 111: while (!(ADC1_SR & ADC1_SR_EOC));
00101$:
	ldw	x, #0x5343
	ld	a, (x)
	srl	a
	jrnc	00101$
;	thermo.c: 112: adcH = ADC1_DRH;
	ldw	x, #0x5344
	ld	a, (x)
;	thermo.c: 113: adcL = ADC1_DRL;
	ldw	x, #0x5345
	push	a
	ld	a, (x)
	ld	xl, a
	pop	a
;	thermo.c: 115: return (adcL | (adcH << 8));
	clr	(0x05, sp)
	clr	(0x04, sp)
	clr	(0x01, sp)
	or	a, (0x01, sp)
	rrwa	x
	or	a, (0x04, sp)
	ld	xl, a
	addw	sp, #6
	ret
;	thermo.c: 119: void initClock() {
;	-----------------------------------------
;	 function initClock
;	-----------------------------------------
_initClock:
;	thermo.c: 120: CLK_CKDIVR = 0; // Set the frequency to 16 MHz
	mov	0x50c0+0, #0x00
;	thermo.c: 121: CLK_PCKENR1 = 0xFF; // Enable peripherals
	mov	0x50c3+0, #0xff
;	thermo.c: 122: CLK_PCKENR2 = 0xFF;
	mov	0x50c4+0, #0xff
	ret
;	thermo.c: 126: int main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	sub	sp, #2
;	thermo.c: 127: initClock();
	call	_initClock
;	thermo.c: 129: enableInterrupts()
	rim
;	thermo.c: 131: initADC();
	call	_initADC
;	thermo.c: 133: initUSART();
	call	_initUSART
;	thermo.c: 135: initMotor();
	call	_initMotor
;	thermo.c: 137: printf("Thermostat: Startup complete\n");
	ldw	x, #___str_0+0
	pushw	x
	call	_printf
	addw	sp, #2
;	thermo.c: 140: while(true) {
00104$:
;	thermo.c: 142: count++;
	ld	a, _count+0
	inc	a
	ld	_count+0, a
;	thermo.c: 143: delay(1000);
	push	#0xe8
	push	#0x03
	clrw	x
	pushw	x
	call	_delay
	addw	sp, #4
;	thermo.c: 144: printf("Loop start: %d \n", count);
	clrw	x
	ld	a, _count+0
	ld	xl, a
	ldw	y, #___str_1+0
	pushw	x
	pushw	y
	call	_printf
	addw	sp, #4
;	thermo.c: 145: adc = readADC();
	call	_readADC
	ldw	(0x01, sp), x
;	thermo.c: 146: printf("ADC value: %d, %d\n", adc, uartBufferPos);
	clrw	x
	ld	a, _uartBufferPos+0
	ld	xl, a
	ldw	y, #___str_2+0
	pushw	x
	ldw	x, (0x03, sp)
	pushw	x
	pushw	y
	call	_printf
	addw	sp, #6
;	thermo.c: 147: if (adc < 2000)
	ldw	x, (0x01, sp)
	cpw	x, #0x07d0
	jrnc	00102$
;	thermo.c: 149: dir = !dir;
	ld	a, _dir+0
	sub	a, #0x01
	clr	a
	rlc	a
	ld	_dir+0, a
00102$:
;	thermo.c: 151: setMotor(dir, !dir);
	ld	a, _dir+0
	sub	a, #0x01
	clr	a
	rlc	a
	push	a
	push	_dir+0
	call	_setMotor
	addw	sp, #2
;	thermo.c: 152: printf("%s\n", readUartBuffer());
	call	_readUartBuffer
	ldw	y, #___str_3+0
	pushw	x
	pushw	y
	call	_printf
	addw	sp, #4
;	thermo.c: 153: clearUartBuffer();
	call	_clearUartBuffer
	jra	00104$
	addw	sp, #2
	ret
;	thermo.c: 162: void uart_isr() __interrupt(UART_RECV_ISR) {
;	-----------------------------------------
;	 function uart_isr
;	-----------------------------------------
_uart_isr:
	clr	a
	div	x, a
	sub	sp, #3
;	thermo.c: 164: uartBufferPos %= UART_BUFFER_SIZE-1;
	clrw	x
	ld	a, _uartBufferPos+0
	ld	xl, a
	ld	a, #0x1f
	div	x, a
;	thermo.c: 165: for(i = uartBufferPos; i < UART_BUFFER_SIZE; i++) {
	ld	_uartBufferPos+0, a
	ldw	x, #_uartBuffer+0
	ldw	(0x02, sp), x
	ld	(0x01, sp), a
00103$:
	ld	a, (0x01, sp)
	cp	a, #0x20
	jrnc	00101$
;	thermo.c: 166: uartBuffer[i] = uartRead();
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	x, (0x02, sp)
	pushw	x
	call	_uartRead
	popw	x
	ld	(x), a
;	thermo.c: 165: for(i = uartBufferPos; i < UART_BUFFER_SIZE; i++) {
	inc	(0x01, sp)
	jra	00103$
00101$:
;	thermo.c: 168: uartBufferPos++;
	ld	a, _uartBufferPos+0
	inc	a
	ld	_uartBufferPos+0, a
	addw	sp, #3
	iret
	.area CODE
___str_0:
	.ascii "Thermostat: Startup complete"
	.db 0x0a
	.db 0x00
___str_1:
	.ascii "Loop start: %d "
	.db 0x0a
	.db 0x00
___str_2:
	.ascii "ADC value: %d, %d"
	.db 0x0a
	.db 0x00
___str_3:
	.ascii "%s"
	.db 0x0a
	.db 0x00
	.area INITIALIZER
__xinit__count:
	.db #0x00	; 0
__xinit__uartBufferPos:
	.db #0x00	; 0
__xinit__dir:
	.db #0x00	;  0
	.area CABS (ABS)
