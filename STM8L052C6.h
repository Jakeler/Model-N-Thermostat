/* STM8L052C6.h */

/* Copyright (c) 2003-2017 STMicroelectronics */

#ifndef __STM8L052C6__
#define __STM8L052C6__

/* STM8L052C6 */

/* functions */
#define enableInterrupts()    {__asm__("rim\n");}    // enable interrupts
#define disableInterrupts()   {__asm__("sim\n");}    // disable interrupts
#define iret()                {__asm__("iret\n");}   // Interrupt routine return
#define pop_ccr()             {__asm__("pop cc\n");} // Pop CCR from the stack
#define push_ccr()            {__asm__("push cc\n");}// Push CCR on the stack
#define rim()                 {__asm__("rim\n");}    // enable interrupts
#define sim()                 {__asm__("sim\n");}    // disable interrupts
#define nop()                 {__asm__("nop\n");}    // No Operation
#define trap()                {__asm__("trap\n");}   // Trap (soft IT)
#define wfi()                 {__asm__("wfi\n");}    // Wait For Interrupt
#define halt()                {__asm__("halt\n");}   // Halt

/* Port A */
/*****************************************************************/

/* Port A data output latch register */
#define PA_ODR (*(volatile uint8_t *)0x5000)

/* Port A input pin value register */
#define PA_IDR (*(volatile uint8_t *)0x5001)

/* Port A data direction register */
#define PA_DDR (*(volatile uint8_t *)0x5002)

/* Port A control register 1 */
#define PA_CR1 (*(volatile uint8_t *)0x5003)

/* Port A control register 2 */
#define PA_CR2 (*(volatile uint8_t *)0x5004)

/* Port B */
/*****************************************************************/

/* Port B data output latch register */
#define PB_ODR (*(volatile uint8_t *)0x5005)

/* Port B input pin value register */
#define PB_IDR (*(volatile uint8_t *)0x5006)

/* Port B data direction register */
#define PB_DDR (*(volatile uint8_t *)0x5007)

/* Port B control register 1 */
#define PB_CR1 (*(volatile uint8_t *)0x5008)

/* Port B control register 2 */
#define PB_CR2 (*(volatile uint8_t *)0x5009)

/* Port C */
/*****************************************************************/

/* Port C data output latch register */
#define PC_ODR (*(volatile uint8_t *)0x500a)

/* Port C input pin value register */
#define PC_IDR (*(volatile uint8_t *)0x500b)

/* Port C data direction register */
#define PC_DDR (*(volatile uint8_t *)0x500c)

/* Port C control register 1 */
#define PC_CR1 (*(volatile uint8_t *)0x500d)

/* Port C control register 2 */
#define PC_CR2 (*(volatile uint8_t *)0x500e)

/* Port D */
/*****************************************************************/

/* Port D data output latch register */
#define PD_ODR (*(volatile uint8_t *)0x500f)

/* Port D input pin value register */
#define PD_IDR (*(volatile uint8_t *)0x5010)

/* Port D data direction register */
#define PD_DDR (*(volatile uint8_t *)0x5011)

/* Port D control register 1 */
#define PD_CR1 (*(volatile uint8_t *)0x5012)

/* Port D control register 2 */
#define PD_CR2 (*(volatile uint8_t *)0x5013)

/* Port E */
/*****************************************************************/

/* Port E data output latch register */
#define PE_ODR (*(volatile uint8_t *)0x5014)

/* Port E input pin value register */
#define PE_IDR (*(volatile uint8_t *)0x5015)

/* Port E data direction register */
#define PE_DDR (*(volatile uint8_t *)0x5016)

/* Port E control register 1 */
#define PE_CR1 (*(volatile uint8_t *)0x5017)

/* Port E control register 2 */
#define PE_CR2 (*(volatile uint8_t *)0x5018)

/* Port F */
/*****************************************************************/

/* Port F data output latch register */
#define PF_ODR (*(volatile uint8_t *)0x5019)

/* Port F input pin value register */
#define PF_IDR (*(volatile uint8_t *)0x501a)

/* Port F data direction register */
#define PF_DDR (*(volatile uint8_t *)0x501b)

/* Port F control register 1 */
#define PF_CR1 (*(volatile uint8_t *)0x501c)

/* Port F control register 2 */
#define PF_CR2 (*(volatile uint8_t *)0x501d)

/* Flash */
/*****************************************************************/

/* Flash control register 1 */
#define FLASH_CR1 (*(volatile uint8_t *)0x5050)

/* Flash control register 2 */
#define FLASH_CR2 (*(volatile uint8_t *)0x5051)

/* Flash Program memory unprotection register */
#define FLASH_PUKR (*(volatile uint8_t *)0x5052)

/* Data EEPROM unprotection register */
#define FLASH_DUKR (*(volatile uint8_t *)0x5053)

/* Flash in-application programming status register */
#define FLASH_IAPSR (*(volatile uint8_t *)0x5054)

/* Direct memory access controller 1 (DMA1) */
/*****************************************************************/

/* DMA1 global configuration & status register */
#define DMA1_GCSR (*(volatile uint8_t *)0x5070)

/* DMA1 global interrupt register 1 */
#define DMA1_GIR1 (*(volatile uint8_t *)0x5071)

/* DMA1 channel 0 configuration register */
#define DMA1_C0CR (*(volatile uint8_t *)0x5075)

/* DMA1 channel 0 status & priority register */
#define DMA1_C0SPR (*(volatile uint8_t *)0x5076)

/* DMA1 number of data to transfer register (channel 0) */
#define DMA1_C0NDTR (*(volatile uint8_t *)0x5077)

/* DMA peripheral address high register (channel 0) */
#define DMA1_C0PARH (*(volatile uint8_t *)0x5078)
/* DMA peripheral address low register (channel 0) */
#define DMA1_C0PARL (*(volatile uint8_t *)0x5079)

/* DMA memory address high register (channel 0) */
#define DMA1_C0M0ARH (*(volatile uint8_t *)0x507b)
/* DMA memory address low register (channel 0) */
#define DMA1_C0M0ARL (*(volatile uint8_t *)0x507c)

/* DMA1 channel 1 configuration register */
#define DMA1_C1CR (*(volatile uint8_t *)0x507f)

/* DMA1 channel 1 status & priority register */
#define DMA1_C1SPR (*(volatile uint8_t *)0x5080)

/* DMA1 number of data to transfer register (channel 1) */
#define DMA1_C1NDTR (*(volatile uint8_t *)0x5081)

/* DMA peripheral address high register (channel 1) */
#define DMA1_C1PARH (*(volatile uint8_t *)0x5082)
/* DMA peripheral address low register (channel 1) */
#define DMA1_C1PARL (*(volatile uint8_t *)0x5083)

/* DMA memory address high register (channel 1) */
#define DMA1_C1M0ARH (*(volatile uint8_t *)0x5085)
/* DMA memory address low register (channel 1) */
#define DMA1_C1M0ARL (*(volatile uint8_t *)0x5086)

/* DMA1 channel 2 configuration register */
#define DMA1_C2CR (*(volatile uint8_t *)0x5089)

/* DMA1 channel 2 status & priority register */
#define DMA1_C2SPR (*(volatile uint8_t *)0x508a)

/* DMA1 number of data to transfer register (channel 2) */
#define DMA1_C2NDTR (*(volatile uint8_t *)0x508b)

/* DMA peripheral address high register (channel 2) */
#define DMA1_C2PARH (*(volatile uint8_t *)0x508c)
/* DMA peripheral address low register (channel 2) */
#define DMA1_C2PARL (*(volatile uint8_t *)0x508d)

/* DMA memory address high register (channel 2) */
#define DMA1_C2M0ARH (*(volatile uint8_t *)0x508f)
/* DMA memory address low register (channel 2) */
#define DMA1_C2M0ARL (*(volatile uint8_t *)0x5090)

/* DMA1 channel 3 configuration register */
#define DMA1_C3CR (*(volatile uint8_t *)0x5093)

/* DMA1 channel 3 status & priority register */
#define DMA1_C3SPR (*(volatile uint8_t *)0x5094)

/* DMA1 number of data to transfer register (channel 3) */
#define DMA1_C3NDTR (*(volatile uint8_t *)0x5095)

/* DMA1 peripheral address high register (channel 3) */
#define DMA1_C3PARH_C3M1ARH (*(volatile uint8_t *)0x5096)
/* DMA1 peripheral address low register (channel 3) */
#define DMA1_C3PARL_C3M1ARL (*(volatile uint8_t *)0x5097)

/* DMA memory address high register (channel 3) */
#define DMA1_C3M0ARH (*(volatile uint8_t *)0x5099)
/* DMA memory address low register (channel 3) */
#define DMA1_C3M0ARL (*(volatile uint8_t *)0x509a)

/* System configuration (SYSCFG) */
/*****************************************************************/

/* Remapping register 1 */
#define SYSCFG_RMPCR1 (*(volatile uint8_t *)0x509e)

/* Remapping register 2 */
#define SYSCFG_RMPCR2 (*(volatile uint8_t *)0x509f)

/* External Interrupt Control Register (ITC) */
/*****************************************************************/

/* External interrupt control register 1 */
#define EXTI_CR1 (*(volatile uint8_t *)0x50a0)

/* External interrupt control register 2 */
#define EXTI_CR2 (*(volatile uint8_t *)0x50a1)

/* External interrupt control register 3 */
#define EXTI_CR3 (*(volatile uint8_t *)0x50a2)

/* External interrupt status register 1 */
#define EXTI_SR1 (*(volatile uint8_t *)0x50a3)

/* External interrupt status register 2 */
#define EXTI_SR2 (*(volatile uint8_t *)0x50a4)

/* External interrupt port select register */
#define EXTI_CONF (*(volatile uint8_t *)0x50a5)

/* Wait For Event (WFE) */
/*****************************************************************/

/* WFE control register 1 */
#define WFE_CR1 (*(volatile uint8_t *)0x50a6)

/* WFE control register 2 */
#define WFE_CR2 (*(volatile uint8_t *)0x50a7)

/* WFE control register 3 */
#define WFE_CR3 (*(volatile uint8_t *)0x50a8)

/* Reset (RST) */
/*****************************************************************/

/* Reset control register */
#define RST_CR (*(volatile uint8_t *)0x50b0)

/* Reset status register */
#define RST_SR (*(volatile uint8_t *)0x50b1)

/* Power control (PWR) */
/*****************************************************************/

/* Power control and status register 1 */
#define PWR_CSR1 (*(volatile uint8_t *)0x50b2)

/* Power control and status register 2 */
#define PWR_CSR2 (*(volatile uint8_t *)0x50b3)

/* Clock Control (CLK) */
/*****************************************************************/

/* System clock divider register */
#define CLK_CKDIVR (*(volatile uint8_t *)0x50c0)

/* Clock RTC register */
#define CLK_CRTCR (*(volatile uint8_t *)0x50c1)

/* Internal clock control register */
#define CLK_ICKCR (*(volatile uint8_t *)0x50c2)

/* Peripheral clock gating register 1 */
#define CLK_PCKENR1 (*(volatile uint8_t *)0x50c3)

/* Peripheral clock gating register 2 */
#define CLK_PCKENR2 (*(volatile uint8_t *)0x50c4)

/* Configurable clock control register */
#define CLK_CCOR (*(volatile uint8_t *)0x50c5)

/* External clock control register */
#define CLK_ECKCR (*(volatile uint8_t *)0x50c6)

/* System clock status register */
#define CLK_SCSR (*(volatile uint8_t *)0x50c7)

/* System clock switch register */
#define CLK_SWR (*(volatile uint8_t *)0x50c8)

/* Clock switch control register */
#define CLK_SWCR (*(volatile uint8_t *)0x50c9)

/* Clock security system register */
#define CLK_CSSR (*(volatile uint8_t *)0x50ca)

/* Clock BEEP register */
#define CLK_CBEEPR (*(volatile uint8_t *)0x50cb)

/* HSI calibration register */
#define CLK_HSICALR (*(volatile uint8_t *)0x50cc)

/* HSI clock calibration trimming register */
#define CLK_HSITRIMR (*(volatile uint8_t *)0x50cd)

/* HSI unlock register */
#define CLK_HSIUNLCKR (*(volatile uint8_t *)0x50ce)

/* Main regulator control status register */
#define CLK_REGCSR (*(volatile uint8_t *)0x50cf)

/* Window Watchdog (WWDG) */
/*****************************************************************/

/* WWDG Control Register */
#define WWDG_CR (*(volatile uint8_t *)0x50d3)

/* WWDR Window Register */
#define WWDG_WR (*(volatile uint8_t *)0x50d4)

/* Independent Watchdog (IWDG) */
/*****************************************************************/

/* IWDG Key Register */
#define IWDG_KR (*(volatile uint8_t *)0x50e0)

/* IWDG Prescaler Register */
#define IWDG_PR (*(volatile uint8_t *)0x50e1)

/* IWDG Reload Register */
#define IWDG_RLR (*(volatile uint8_t *)0x50e2)

/* Beeper (BEEP) */
/*****************************************************************/

/* BEEP Control/Status Register 1 */
#define BEEP_CSR1 (*(volatile uint8_t *)0x50f0)

/* BEEP Control/Status Register 2 */
#define BEEP_CSR2 (*(volatile uint8_t *)0x50f3)

/* Real-time clock (RTC) */
/*****************************************************************/

/* Time Register 1 */
#define RTC_TR1 (*(volatile uint8_t *)0x5140)

/* Time Register 2 */
#define RTC_TR2 (*(volatile uint8_t *)0x5141)

/* Time Register 3 */
#define RTC_TR3 (*(volatile uint8_t *)0x5142)

/* Date Register 1 */
#define RTC_DR1 (*(volatile uint8_t *)0x5144)

/* Date Register 2 */
#define RTC_DR2 (*(volatile uint8_t *)0x5145)

/* Date Register 3 */
#define RTC_DR3 (*(volatile uint8_t *)0x5146)

/* Control Register 1 */
#define RTC_CR1 (*(volatile uint8_t *)0x5148)

/* Control Register 2 */
#define RTC_CR2 (*(volatile uint8_t *)0x5149)

/* Control Register 3 */
#define RTC_CR3 (*(volatile uint8_t *)0x514a)

/* Initialization and Status Register 1 */
#define RTC_ISR1 (*(volatile uint8_t *)0x514c)

/* Initialization and Status Register 2 */
#define RTC_ISR2 (*(volatile uint8_t *)0x514d)

/* Synchronous Prescaler Register High */
#define RTC_SPRERH (*(volatile uint8_t *)0x5150)
/* Synchronous Prescaler Register Low */
#define RTC_SPRERL (*(volatile uint8_t *)0x5151)

/* Asynchronous Prescaler Register */
#define RTC_APRER (*(volatile uint8_t *)0x5152)

/* Wakeup Timer Register High */
#define RTC_WUTRH (*(volatile uint8_t *)0x5154)
/* Wakeup Timer Register Low */
#define RTC_WUTRL (*(volatile uint8_t *)0x5155)

/* Write Protection Register */
#define RTC_WPR (*(volatile uint8_t *)0x5159)

/* Alarm A Register 1 */
#define RTC_ALRMAR1 (*(volatile uint8_t *)0x515c)

/* Alarm A Register 2 */
#define RTC_ALRMAR2 (*(volatile uint8_t *)0x515d)

/* Alarm A Register 3 */
#define RTC_ALRMAR3 (*(volatile uint8_t *)0x515e)

/* Alarm A Register 4 */
#define RTC_ALRMAR4 (*(volatile uint8_t *)0x515f)

/* Serial Peripheral Interface 1 (SPI1) */
/*****************************************************************/

/* SPI1 Control Register 1 */
#define SPI1_CR1 (*(volatile uint8_t *)0x5200)

/* SPI1 Control Register 2 */
#define SPI1_CR2 (*(volatile uint8_t *)0x5201)

/* SPI1 Interrupt Control Register */
#define SPI1_ICR (*(volatile uint8_t *)0x5202)

/* SPI1 Status Register */
#define SPI1_SR (*(volatile uint8_t *)0x5203)

/* SPI1 Data Register */
#define SPI1_DR (*(volatile uint8_t *)0x5204)

/* SPI1 CRC Polynomial Register */
#define SPI1_CRCPR (*(volatile uint8_t *)0x5205)

/* SPI1 Rx CRC Register */
#define SPI1_RXCRCR (*(volatile uint8_t *)0x5206)

/* SPI1 Tx CRC Register */
#define SPI1_TXCRCR (*(volatile uint8_t *)0x5207)

/* I2C Bus Interface 1 (I2C1) */
/*****************************************************************/

/* I2C1 control register 1 */
#define I2C1_CR1 (*(volatile uint8_t *)0x5210)

/* I2C1 control register 2 */
#define I2C1_CR2 (*(volatile uint8_t *)0x5211)

/* I2C1 frequency register */
#define I2C1_FREQR (*(volatile uint8_t *)0x5212)

/* I2C1 Own address register low */
#define I2C1_OARL (*(volatile uint8_t *)0x5213)

/* I2C1 Own address register high */
#define I2C1_OARH (*(volatile uint8_t *)0x5214)

/* I2C1 data register */
#define I2C1_DR (*(volatile uint8_t *)0x5216)

/* I2C1 status register 1 */
#define I2C1_SR1 (*(volatile uint8_t *)0x5217)

/* I2C1 status register 2 */
#define I2C1_SR2 (*(volatile uint8_t *)0x5218)

/* I2C1 status register 3 */
#define I2C1_SR3 (*(volatile uint8_t *)0x5219)

/* I2C1 interrupt control register */
#define I2C1_ITR (*(volatile uint8_t *)0x521a)

/* I2C1 Clock control register low */
#define I2C1_CCRL (*(volatile uint8_t *)0x521b)

/* I2C1 Clock control register high */
#define I2C1_CCRH (*(volatile uint8_t *)0x521c)

/* I2C1 TRISE register */
#define I2C1_TRISER (*(volatile uint8_t *)0x521d)

/* I2C1 packet error checking register */
#define I2C1_PECR (*(volatile uint8_t *)0x521e)

/* Universal synch/asynch receiver transmitter 1 (USART1) */
/*****************************************************************/

/* USART1 Status Register */
#define USART1_SR (*(volatile uint8_t *)0x5230)

/* USART1 Data Register */
#define USART1_DR (*(volatile uint8_t *)0x5231)

/* USART1 Baud Rate Register 1 */
#define USART1_BRR1 (*(volatile uint8_t *)0x5232)

/* USART1 Baud Rate Register 2 */
#define USART1_BRR2 (*(volatile uint8_t *)0x5233)

/* USART1 Control Register 1 */
#define USART1_CR1 (*(volatile uint8_t *)0x5234)

/* USART1 Control Register 2 */
#define USART1_CR2 (*(volatile uint8_t *)0x5235)

/* USART1 Control Register 3 */
#define USART1_CR3 (*(volatile uint8_t *)0x5236)

/* USART1 Control Register 4 */
#define USART1_CR4 (*(volatile uint8_t *)0x5237)

/* USART1 Control Register 5 */
#define USART1_CR5 (*(volatile uint8_t *)0x5238)

/* USART1 Guard time Register */
#define USART1_GTR (*(volatile uint8_t *)0x5239)

/* USART1 Prescaler Register */
#define USART1_PSCR (*(volatile uint8_t *)0x523a)

/* 16-Bit Timer 2 (TIM2) */
/*****************************************************************/

/* TIM2 Control register 1 */
#define TIM2_CR1 (*(volatile uint8_t *)0x5250)

/* TIM2 Control register 2 */
#define TIM2_CR2 (*(volatile uint8_t *)0x5251)

/* TIM2 Slave Mode Control register */
#define TIM2_SMCR (*(volatile uint8_t *)0x5252)

/* TIM2 External trigger register */
#define TIM2_ETR (*(volatile uint8_t *)0x5253)

/* TIM2 DMA request enable register */
#define TIM2_DER (*(volatile uint8_t *)0x5254)

/* TIM2 Interrupt enable register */
#define TIM2_IER (*(volatile uint8_t *)0x5255)

/* TIM2 Status register 1 */
#define TIM2_SR1 (*(volatile uint8_t *)0x5256)

/* TIM2 Status register 2 */
#define TIM2_SR2 (*(volatile uint8_t *)0x5257)

/* TIM2 Event Generation register */
#define TIM2_EGR (*(volatile uint8_t *)0x5258)

/* TIM2 Capture/Compare mode register 1 */
#define TIM2_CCMR1 (*(volatile uint8_t *)0x5259)

/* TIM2 Capture/Compare mode register 2 */
#define TIM2_CCMR2 (*(volatile uint8_t *)0x525a)

/* TIM2 Capture/Compare enable register 1 */
#define TIM2_CCER1 (*(volatile uint8_t *)0x525b)

/* TIM2 Counter High */
#define TIM2_CNTRH (*(volatile uint8_t *)0x525c)
/* TIM2 Counter Low */
#define TIM2_CNTRL (*(volatile uint8_t *)0x525d)

/* TIM2 Prescaler register */
#define TIM2_PSCR (*(volatile uint8_t *)0x525e)

/* TIM2 Auto-Reload Register High */
#define TIM2_ARRH (*(volatile uint8_t *)0x525f)
/* TIM2 Auto-Reload Register Low */
#define TIM2_ARRL (*(volatile uint8_t *)0x5260)

/* TIM2 Capture/Compare Register 1 High */
#define TIM2_CCR1H (*(volatile uint8_t *)0x5261)
/* TIM2 Capture/Compare Register 1 Low */
#define TIM2_CCR1L (*(volatile uint8_t *)0x5262)

/* TIM2 Capture/Compare Register 2 High */
#define TIM2_CCR2H (*(volatile uint8_t *)0x5263)
/* TIM2 Capture/Compare Register 2 Low */
#define TIM2_CCR2L (*(volatile uint8_t *)0x5264)

/* TIM2 Break register */
#define TIM2_BKR (*(volatile uint8_t *)0x5265)

/* TIM2 Output idle state register */
#define TIM2_OISR (*(volatile uint8_t *)0x5266)

/* 16-Bit Timer 3 (TIM3) */
/*****************************************************************/

/* TIM3 Control register 1 */
#define TIM3_CR1 (*(volatile uint8_t *)0x5280)

/* TIM3 Control register 2 */
#define TIM3_CR2 (*(volatile uint8_t *)0x5281)

/* TIM3 Slave Mode Control register */
#define TIM3_SMCR (*(volatile uint8_t *)0x5282)

/* TIM3 External trigger register */
#define TIM3_ETR (*(volatile uint8_t *)0x5283)

/* TIM3 DMA request enable register */
#define TIM3_DER (*(volatile uint8_t *)0x5284)

/* TIM3 Interrupt enable register */
#define TIM3_IER (*(volatile uint8_t *)0x5285)

/* TIM3 Status register 1 */
#define TIM3_SR1 (*(volatile uint8_t *)0x5286)

/* TIM3 Status register 2 */
#define TIM3_SR2 (*(volatile uint8_t *)0x5287)

/* TIM3 Event Generation register */
#define TIM3_EGR (*(volatile uint8_t *)0x5288)

/* TIM3 Capture/Compare mode register 1 */
#define TIM3_CCMR1 (*(volatile uint8_t *)0x5289)

/* TIM3 Capture/Compare mode register 2 */
#define TIM3_CCMR2 (*(volatile uint8_t *)0x528a)

/* TIM3 Capture/Compare enable register 1 */
#define TIM3_CCER1 (*(volatile uint8_t *)0x528b)

/* TIM3 Counter High */
#define TIM3_CNTRH (*(volatile uint8_t *)0x528c)
/* TIM3 Counter Low */
#define TIM3_CNTRL (*(volatile uint8_t *)0x528d)

/* TIM3 Prescaler register */
#define TIM3_PSCR (*(volatile uint8_t *)0x528e)

/* TIM3 Auto-Reload Register High */
#define TIM3_ARRH (*(volatile uint8_t *)0x528f)
/* TIM3 Auto-Reload Register Low */
#define TIM3_ARRL (*(volatile uint8_t *)0x5290)

/* TIM3 Capture/Compare Register 1 High */
#define TIM3_CCR1H (*(volatile uint8_t *)0x5291)
/* TIM3 Capture/Compare Register 1 Low */
#define TIM3_CCR1L (*(volatile uint8_t *)0x5292)

/* TIM3 Capture/Compare Register 2 High */
#define TIM3_CCR2H (*(volatile uint8_t *)0x5293)
/* TIM3 Capture/Compare Register 2 Low */
#define TIM3_CCR2L (*(volatile uint8_t *)0x5294)

/* TIM3 Break register */
#define TIM3_BKR (*(volatile uint8_t *)0x5295)

/* TIM3 Output idle state register */
#define TIM3_OISR (*(volatile uint8_t *)0x5296)

/* 16-Bit Timer 1 (TIM1) */
/*****************************************************************/

/* TIM1 Control register 1 */
#define TIM1_CR1 (*(volatile uint8_t *)0x52b0)

/* TIM1 Control register 2 */
#define TIM1_CR2 (*(volatile uint8_t *)0x52b1)

/* TIM1 Slave Mode Control register */
#define TIM1_SMCR (*(volatile uint8_t *)0x52b2)

/* TIM1 external trigger register */
#define TIM1_ETR (*(volatile uint8_t *)0x52b3)

/* TIM1 DMA request enable register */
#define TIM1_DER (*(volatile uint8_t *)0x52b4)

/* TIM1 Interrupt enable register */
#define TIM1_IER (*(volatile uint8_t *)0x52b5)

/* TIM1 Status register 1 */
#define TIM1_SR1 (*(volatile uint8_t *)0x52b6)

/* TIM1 Status register 2 */
#define TIM1_SR2 (*(volatile uint8_t *)0x52b7)

/* TIM1 Event Generation register */
#define TIM1_EGR (*(volatile uint8_t *)0x52b8)

/* TIM1 Capture/Compare mode register 1 */
#define TIM1_CCMR1 (*(volatile uint8_t *)0x52b9)

/* TIM1 Capture/Compare mode register 2 */
#define TIM1_CCMR2 (*(volatile uint8_t *)0x52ba)

/* TIM1 Capture/Compare mode register 3 */
#define TIM1_CCMR3 (*(volatile uint8_t *)0x52bb)

/* TIM1 Capture/Compare mode register 4 */
#define TIM1_CCMR4 (*(volatile uint8_t *)0x52bc)

/* TIM1 Capture/Compare enable register 1 */
#define TIM1_CCER1 (*(volatile uint8_t *)0x52bd)

/* TIM1 Capture/Compare enable register 2 */
#define TIM1_CCER2 (*(volatile uint8_t *)0x52be)

/* TIM1 Counter High */
#define TIM1_CNTRH (*(volatile uint8_t *)0x52bf)
/* TIM1 Counter Low */
#define TIM1_CNTRL (*(volatile uint8_t *)0x52c0)

/* TIM1 Prescaler Register High */
#define TIM1_PSCRH (*(volatile uint8_t *)0x52c1)
/* TIM1 Prescaler Register Low */
#define TIM1_PSCRL (*(volatile uint8_t *)0x52c2)

/* TIM1 Auto-Reload Register High */
#define TIM1_ARRH (*(volatile uint8_t *)0x52c3)
/* TIM1 Auto-Reload Register Low */
#define TIM1_ARRL (*(volatile uint8_t *)0x52c4)

/* TIM1 Repetition counter register */
#define TIM1_RCR (*(volatile uint8_t *)0x52c5)

/* TIM1 Capture/Compare Register 1 High */
#define TIM1_CCR1H (*(volatile uint8_t *)0x52c6)
/* TIM1 Capture/Compare Register 1 Low */
#define TIM1_CCR1L (*(volatile uint8_t *)0x52c7)

/* TIM1 Capture/Compare Register 2 High */
#define TIM1_CCR2H (*(volatile uint8_t *)0x52c8)
/* TIM1 Capture/Compare Register 2 Low */
#define TIM1_CCR2L (*(volatile uint8_t *)0x52c9)

/* TIM1 Capture/Compare Register 3 High */
#define TIM1_CCR3H (*(volatile uint8_t *)0x52ca)
/* TIM1 Capture/Compare Register 3 Low */
#define TIM1_CCR3L (*(volatile uint8_t *)0x52cb)

/* TIM1 Capture/Compare Register 4 High */
#define TIM1_CCR4H (*(volatile uint8_t *)0x52cc)
/* TIM1 Capture/Compare Register 4 Low */
#define TIM1_CCR4L (*(volatile uint8_t *)0x52cd)

/* TIM1 Break register */
#define TIM1_BKR (*(volatile uint8_t *)0x52ce)

/* TIM1 Dead-time register */
#define TIM1_DTR (*(volatile uint8_t *)0x52cf)

/* TIM1 Output idle state register */
#define TIM1_OISR (*(volatile uint8_t *)0x52d0)

/* TIM1 DMA control register 1 */
#define TIM1_DCR1 (*(volatile uint8_t *)0x52d1)

/* TIM1 DMA control register 2 */
#define TIM1_DCR2 (*(volatile uint8_t *)0x52d2)

/* TIM1 DMA address for burst mode */
#define TIM1_DMAR (*(volatile uint8_t *)0x52d3)

/* 8-Bit  Timer 4 (TIM4) */
/*****************************************************************/

/* TIM4 Control Register 1 */
#define TIM4_CR1 (*(volatile uint8_t *)0x52e0)

/* TIM4 Control Register 2 */
#define TIM4_CR2 (*(volatile uint8_t *)0x52e1)

/* TIM4 Slave Mode Control Register */
#define TIM4_SMCR (*(volatile uint8_t *)0x52e2)

/* TIM4 DMA request Enable Register */
#define TIM4_DER (*(volatile uint8_t *)0x52e3)

/* TIM4 Interrupt Enable Register */
#define TIM4_IER (*(volatile uint8_t *)0x52e4)

/* TIM4 Status Register 1 */
#define TIM4_SR1 (*(volatile uint8_t *)0x52e5)

/* TIM4 Event Generation Register */
#define TIM4_EGR (*(volatile uint8_t *)0x52e6)

/* TIM4 Counter */
#define TIM4_CNTR (*(volatile uint8_t *)0x52e7)

/* TIM4 Prescaler Register */
#define TIM4_PSCR (*(volatile uint8_t *)0x52e8)

/* TIM4 Auto-Reload Register */
#define TIM4_ARR (*(volatile uint8_t *)0x52e9)

/* Infra Red Interface (IR) */
/*****************************************************************/

/* Infra-red control register */
#define IR_CR (*(volatile uint8_t *)0x52ff)

/* Analog to digital converter 1 (ADC1) */
/*****************************************************************/

/* ADC1 Configuration register 1 */
#define ADC1_CR1 (*(volatile uint8_t *)0x5340)

/* ADC1 Configuration register 2 */
#define ADC1_CR2 (*(volatile uint8_t *)0x5341)

/* ADC1 Configuration register 3 */
#define ADC1_CR3 (*(volatile uint8_t *)0x5342)

/* ADC1 status register */
#define ADC1_SR (*(volatile uint8_t *)0x5343)

/* ADC Data Register High */
#define ADC1_DRH (*(volatile uint8_t *)0x5344)
/* ADC Data Register Low */
#define ADC1_DRL (*(volatile uint8_t *)0x5345)

/* ADC High Threshold Register High */
#define ADC1_HTRH (*(volatile uint8_t *)0x5346)
/* ADC High Threshold Register Low */
#define ADC1_HTRL (*(volatile uint8_t *)0x5347)

/* ADC Low Threshold Register High */
#define ADC1_LTRH (*(volatile uint8_t *)0x5348)
/* ADC Low Threshold Register Low */
#define ADC1_LTRL (*(volatile uint8_t *)0x5349)

/* ADC1 channel sequence 1 register */
#define ADC1_SQR1 (*(volatile uint8_t *)0x534a)

/* ADC1 channel sequence 2 register */
#define ADC1_SQR2 (*(volatile uint8_t *)0x534b)

/* ADC1 channel sequence 3 register */
#define ADC1_SQR3 (*(volatile uint8_t *)0x534c)

/* ADC1 channel sequence 4 register */
#define ADC1_SQR4 (*(volatile uint8_t *)0x534d)

/* ADC1 Trigger disable 1 */
#define ADC1_TRIGR1 (*(volatile uint8_t *)0x534e)

/* ADC1 Trigger disable 2 */
#define ADC1_TRIGR2 (*(volatile uint8_t *)0x534f)

/* ADC1 Trigger disable 3 */
#define ADC1_TRIGR3 (*(volatile uint8_t *)0x5350)

/* ADC1 Trigger disable 4 */
#define ADC1_TRIGR4 (*(volatile uint8_t *)0x5351)

/* LCD controller (LCD) */
/*****************************************************************/

/* LCD control register 1 */
#define LCD_CR1 (*(volatile uint8_t *)0x5400)

/* LCD control register 2 */
#define LCD_CR2 (*(volatile uint8_t *)0x5401)

/* LCD control register 3 */
#define LCD_CR3 (*(volatile uint8_t *)0x5402)

/* LCD frequency selection register */
#define LCD_FRQ (*(volatile uint8_t *)0x5403)

/* LCD Port mask register 0 */
#define LCD_PM0 (*(volatile uint8_t *)0x5404)

/* LCD Port mask register 1 */
#define LCD_PM1 (*(volatile uint8_t *)0x5405)

/* LCD Port mask register 2 */
#define LCD_PM2 (*(volatile uint8_t *)0x5406)

/* LCD display memory 0 */
#define LCD_RAM0 (*(volatile uint8_t *)0x540c)

/* LCD display memory 1 */
#define LCD_RAM1 (*(volatile uint8_t *)0x540d)

/* LCD display memory 2 */
#define LCD_RAM2 (*(volatile uint8_t *)0x540e)

/* LCD display memory 3 */
#define LCD_RAM3 (*(volatile uint8_t *)0x540f)

/* LCD display memory 4 */
#define LCD_RAM4 (*(volatile uint8_t *)0x5410)

/* LCD display memory 5 */
#define LCD_RAM5 (*(volatile uint8_t *)0x5411)

/* LCD display memory 6 */
#define LCD_RAM6 (*(volatile uint8_t *)0x5412)

/* LCD display memory 7 */
#define LCD_RAM7 (*(volatile uint8_t *)0x5413)

/* LCD display memory 8 */
#define LCD_RAM8 (*(volatile uint8_t *)0x5414)

/* LCD display memory 9 */
#define LCD_RAM9 (*(volatile uint8_t *)0x5415)

/* LCD display memory 10 */
#define LCD_RAM10 (*(volatile uint8_t *)0x5416)

/* LCD display memory 11 */
#define LCD_RAM11 (*(volatile uint8_t *)0x5417)

/* LCD display memory 12 */
#define LCD_RAM12 (*(volatile uint8_t *)0x5418)

/* LCD display memory 13 */
#define LCD_RAM13 (*(volatile uint8_t *)0x5419)

/* Routing interface (RI) */
/*****************************************************************/

/* Timer input capture routing register 1 */
#define RI_ICR1 (*(volatile uint8_t *)0x5431)

/* Timer input capture routing register 2 */
#define RI_ICR2 (*(volatile uint8_t *)0x5432)

/* I/O input register 1 */
#define RI_IOIR1 (*(volatile uint8_t *)0x5433)

/* I/O input register 2 */
#define RI_IOIR2 (*(volatile uint8_t *)0x5434)

/* I/O input register 3 */
#define RI_IOIR3 (*(volatile uint8_t *)0x5435)

/* I/O control mode register 1 */
#define RI_IOCMR1 (*(volatile uint8_t *)0x5436)

/* I/O control mode register 2 */
#define RI_IOCMR2 (*(volatile uint8_t *)0x5437)

/* I/O control mode register 3 */
#define RI_IOCMR3 (*(volatile uint8_t *)0x5438)

/* I/O switch register 1 */
#define RI_IOSR1 (*(volatile uint8_t *)0x5439)

/* I/O switch register 2 */
#define RI_IOSR2 (*(volatile uint8_t *)0x543a)

/* I/O switch register 3 */
#define RI_IOSR3 (*(volatile uint8_t *)0x543b)

/* I/O group control register */
#define RI_IOGCR (*(volatile uint8_t *)0x543c)

/* Analog switch register 1 */
#define RI_ASCR1 (*(volatile uint8_t *)0x543d)

/* Analog switch register 2 */
#define RI_ASCR2 (*(volatile uint8_t *)0x543e)

/* Resistor control register */
#define RI_RCR (*(volatile uint8_t *)0x543f)

// Custom bits
#define USART_CR1_R8 (1 << 7)
#define USART_CR1_T8 (1 << 6)
#define USART_CR1_UARTD (1 << 5)
#define USART_CR1_M (1 << 4)
#define USART_CR1_WAKE (1 << 3)
#define USART_CR1_PCEN (1 << 2)
#define USART_CR1_PS (1 << 1)
#define USART_CR1_PIEN (1 << 0)
#define USART_CR2_TIEN (1 << 7)
#define USART_CR2_TCIEN (1 << 6)
#define USART_CR2_RIEN (1 << 5)
#define USART_CR2_ILIEN (1 << 4)
#define USART_CR2_TEN (1 << 3)
#define USART_CR2_REN (1 << 2)
#define USART_CR2_RWU (1 << 1)
#define USART_CR2_SBK (1 << 0)
#define USART_CR3_LINEN (1 << 6)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_CR3_CLKEN (1 << 3)
#define USART_CR3_CPOL (1 << 2)
#define USART_CR3_CPHA (1 << 1)
#define USART_CR3_LBCL (1 << 0)
#define USART_SR_TXE (1 << 7)
#define USART_SR_TC (1 << 6)
#define USART_SR_RXNE (1 << 5)
#define USART_SR_IDLE (1 << 4)
#define USART_SR_OR (1 << 3)
#define USART_SR_NF (1 << 2)
#define USART_SR_FE (1 << 1)
#define USART_SR_PE (1 << 0)

#define TIM_IER_BIE (1 << 7)
#define TIM_IER_TIE (1 << 6)
#define TIM_IER_COMIE (1 << 5)
#define TIM_IER_CC4IE (1 << 4)
#define TIM_IER_CC3IE (1 << 3)
#define TIM_IER_CC2IE (1 << 2)
#define TIM_IER_CC1IE (1 << 1)

#define TIM_IER_UIE (1 << 0)
#define TIM_CR1_APRE (1 << 7)
#define TIM_CR1_CMSH (1 << 6)
#define TIM_CR1_CMSL (1 << 5)
#define TIM_CR1_DIR (1 << 4)
#define TIM_CR1_OPM (1 << 3)
#define TIM_CR1_URS (1 << 2)
#define TIM_CR1_UDIS (1 << 1)
#define TIM_CR1_CEN (1 << 0)

#define TIM_SR1_BIF (1 << 7)
#define TIM_SR1_TIF (1 << 6)
#define TIM_SR1_COMIF (1 << 5)
#define TIM_SR1_CC4IF (1 << 4)
#define TIM_SR1_CC3IF (1 << 3)
#define TIM_SR1_CC2IF (1 << 2)
#define TIM_SR1_CC1IF (1 << 1)
#define TIM_SR1_UIF (1 << 0)

#define ADC1_CR1_OVERIE (1 << 7)
#define ADC1_CR1_RES1 (1 << 6)
#define ADC1_CR1_RES0 (1 << 5)
#define ADC1_CR1_AWDIE (1 << 4)
#define ADC1_CR1_EOCIE (1 << 3)
#define ADC1_CR1_CONT (1 << 2)
#define ADC1_CR1_START (1 << 1)
#define ADC1_CR1_ADON (1 << 0)

#define ADC1_SR_OVER (1 << 2)
#define ADC1_SR_AWD (1 << 1)
#define ADC1_SR_EOC (1 << 0)

#define ADC1_SQR1_DMAOFF (1 << 7)

#endif /* __STM8L052C6__ */
