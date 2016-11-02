#ifndef storm_soc_basic_h
#define storm_soc_basic_h

/////////////////////////////////////////////////////////////////
// storm_soc_basic.h - STORM SoC Basic Configuration
// Based on the STORM Core Processor System
//
// Created by Stephan Nolting (stnolting@googlemail.com)
// http://www.opencores.com/project,storm_core
// http://www.opencores.com/project,storm_soc
// Last modified 15. May 2012
/////////////////////////////////////////////////////////////////

#define REG32 (volatile unsigned long*)

/* Internal RAM */
#define IRAM_BASE       (*(REG32 (0x00000000)))
#define IRAM_SIZE       32*1024

/* External RAM */
#define XRAM_BASE       (*(REG32 (0x04000000)))
#define XRAM_SIZE       32*1024*1024

/* Complete RAM */
#define RAM_BASE        (*(REG32 (0x00000000)))
#define RAM_SIZE        IRAM_SIZE + XRAM_SIZE

/* Internal ROM (boot ROM) */
#define ROM_BASE        (*(REG32 (0xFFF00000)))
#define ROM_SIZE        8*1024

/* De-Cached IO Area */
#define IO_AREA_BEGIN   (*(REG32 (0xFFFE0000)))
#define IO_AREA_END     (*(REG32 (0xFFFFFFFF)))
#define IO_AREA_SIZE    524288;

/* General Purpose IO Controller 0 */
#define GPIO0_BASE      (*(REG32 (0xFFFF0000)))
#define GPIO0_SIZE      2*4
#define GPIO0_OUT       (*(REG32 (0xFFFF0000)))
#define GPIO0_IN        (*(REG32 (0xFFFF0004)))

/* UART 0 - miniUART */
#define UART0_BASE      (*(REG32 (FFFF0100)))
#define UART0_SIZE      2*4
#define UART0_DATA      (*(REG32 (0xFFFF0100)))
#define UART0_SREG      (*(REG32 (0xFFFF0104)))

/* Mini UART */
#define CUART_TXB       0 // transmitter busy
#define CUART_RXD       1 // byte available

/* Amber UART */
#define UART1_DR             (*(REG32 (0xFFFF0000)))
#define UART1_RSR            (*(REG32 (0xFFFF0004)))
#define UART1_LCRH           (*(REG32 (0xFFFF0008)))
#define UART1_LCRM           (*(REG32 (0xFFFF000C)))
#define UART1_LCRL           (*(REG32 (0xFFFF0010)))
#define UART1_CR             (*(REG32 (0xFFFF0014)))
#define UART1_FR             (*(REG32 (0xFFFF0018)))
#define UART1_IIR            (*(REG32 (0xFFFF001C)))
#define UART1_ICR            (*(REG32 (0xFFFF001C)))

/* System Timer 0 */
/* #define STME0_BASE      (*(REG32 (0xFFFF0020)))
#define STME0_SIZE      4*4
#define STME0_CNT       (*(REG32 (0xFFFF0020)))
#define STME0_VAL       (*(REG32 (0xFFFF0024)))
#define STME0_CONF      (*(REG32 (0xFFFF0028)))
#define STME0_SCRT      (*(REG32 (0xFFFF002C)))
 */
#define TIMER0_LOAD       (*(REG32 (0xFFFE1000)))
#define TIMER0_VALUE      (*(REG32 (0xFFFE1004)))
#define TIMER0_CTRL       (*(REG32 (0xFFFE1008)))
#define TIMER0_CLR        (*(REG32 (0xFFFE100C)))

#define TIMER1_LOAD       (*(REG32 (0xFFFE1100)))
#define TIMER1_VALUE      (*(REG32 (0xFFFE1104)))
#define TIMER1_CTRL       (*(REG32 (0xFFFE1108)))
#define TIMER1_CLR        (*(REG32 (0xFFFE110C)))

#define TIMER2_LOAD       (*(REG32 (0xFFFE1200)))
#define TIMER2_VALUE      (*(REG32 (0xFFFE1204)))
#define TIMER2_CTRL       (*(REG32 (0xFFFE1208)))
#define TIMER2_CLR        (*(REG32 (0xFFFE120C)))

//-------------------Backwards Compatability Begin--------------
#define STME0_SIZE      4*4
#define STME0_CNT       TIMER0_LOAD
#define STME0_VAL       TIMER0_VALUE
#define STME0_CONF      TIMER0_CTRL
#define STME0_SCRT      TIMER0_CLR
//-------------------Backwards Compatability End--------------

/* SPI Controller 0 */
#define SPI0_BASE       (*(REG32 (0xFFFF0030)))
#define SPI0_SIZE       8*4
#define SPI0_CONF       (*(REG32 (0xFFFF0030)))
#define SPI0_PRSC       (*(REG32 (0xFFFF0034)))
#define SPI0_SCSR       (*(REG32 (0xFFFF0038)))
// unused location      (*(REG32 (0xFFFF003C)))
#define SPI0_DAT0       (*(REG32 (0xFFFF0040)))
#define SPI0_DAT1       (*(REG32 (0xFFFF0044)))
#define SPI0_DAT2       (*(REG32 (0xFFFF0048)))
#define SPI0_DAT3       (*(REG32 (0xFFFF004C)))

/* Serial Peripherial Interface Controller 0 */
#define SPI_BUSY         8 // spi busy
#define SPI_RX_NEG       9 // load miso on falling edge of sclk
#define SPI_TX_NEG      10 // change mosi on falling edge of sclk
#define SPI_ACS         13 // manual/auto assert cs

/* I�C Controller 0 */
#define I2C0_BASE       (*(REG32 (0xFFFF0050)))
#define I2C0_SIZE       8*4
#define I2C0_CMD        (*(REG32 (0xFFFF0050)))
#define I2C0_STAT       (*(REG32 (0xFFFF0050)))
// unused location      (*(REG32 (0xFFFF0054)))
// unused location      (*(REG32 (0xFFFF0058)))
// unused location      (*(REG32 (0xFFFF005C)))
#define I2C0_PRLO       (*(REG32 (0xFFFF0060)))
#define I2C0_PRHI       (*(REG32 (0xFFFF0064)))
#define I2C0_CTRL       (*(REG32 (0xFFFF0068)))
#define I2C0_DATA       (*(REG32 (0xFFFF006C)))

/* I�C Controller 0 */
#define I2C_EN           7 // enable core

#define I2C_STA          7 // generate start condition
#define I2C_STO          6 // generate stop condition
#define I2C_RD           5 // read
#define I2C_WR           4 // write
#define I2C_ACK          3 // acknowledge
#define I2C_IACK         0 // interrupt ack

#define I2C_RXACK        7 // ack from slave received
#define I2C_BUSY         6 // i2c busy
#define I2C_TIP          1 // transfer in progress

/* PWM Controller 0 */
// #define PWM0_BASE       (*(REG32 (0xFFFF0070)))
// #define PWM0_SIZE       2*4
// #define PWM0_CONF0      (*(REG32 (0xFFFF0070)))
// #define PWM0_CONF1      (*(REG32 (0xFFFF0074)))

/* Vector Interrupt Controller */
/* 
#define VIC_BASE        (*(REG32 (0xFFFE2000)))
#define VIC_SIZE        64*4
#define VICIRQStatus    (*(REG32 (0xFFFE2000)))
#define VICFIQStatus    (*(REG32 (0xFFFE2000)))
#define VICRawIntr      (*(REG32 (0xFFFE2000)))
#define VICIntSelect    (*(REG32 (0xFFFE2000)))
#define VICIntEnable    (*(REG32 (0xFFFE2000)))
#define VICIntEnClear   (*(REG32 (0xFFFE2000)))
#define VICSoftInt      (*(REG32 (0xFFFE2000)))
#define VICSoftIntClear (*(REG32 (0xFFFE2000)))
#define VICProtection   (*(REG32 (0xFFFE2000)))
#define VICVectAddr     (*(REG32 (0xFFFE2000)))
#define VICDefVectAddr  (*(REG32 (0xFFFE2000)))
#define VICTrigLevel    (*(REG32 (0xFFFE2000)))
#define VICTrigMode     (*(REG32 (0xFFFE2000)))
#define VICVectAddr0    (*(REG32 (0xFFFE2000)))
#define VICVectAddr1    (*(REG32 (0xFFFE2000)))
#define VICVectAddr2    (*(REG32 (0xFFFE2000)))
#define VICVectAddr3    (*(REG32 (0xFFFE2000)))
#define VICVectAddr4    (*(REG32 (0xFFFE2000)))
#define VICVectAddr5    (*(REG32 (0xFFFE2000)))
#define VICVectAddr6    (*(REG32 (0xFFFE2000)))
#define VICVectAddr7    (*(REG32 (0xFFFE2000)))
#define VICVectAddr8    (*(REG32 (0xFFFE2000)))
#define VICVectAddr9    (*(REG32 (0xFFFE2000)))
#define VICVectAddr10   (*(REG32 (0xFFFE2000)))
#define VICVectAddr11   (*(REG32 (0xFFFE2000)))
#define VICVectAddr12   (*(REG32 (0xFFFE2000)))
#define VICVectAddr13   (*(REG32 (0xFFFE2000)))
#define VICVectAddr14   (*(REG32 (0xFFFE2000)))
#define VICVectAddr15   (*(REG32 (0xFFFE2000)))
#define VICVectCntl0    (*(REG32 (0xFFFE2000)))
#define VICVectCntl1    (*(REG32 (0xFFFE2000)))
#define VICVectCntl2    (*(REG32 (0xFFFE2000)))
#define VICVectCntl3    (*(REG32 (0xFFFE2000)))
#define VICVectCntl4    (*(REG32 (0xFFFE2000)))
#define VICVectCntl5    (*(REG32 (0xFFFE2000)))
#define VICVectCntl6    (*(REG32 (0xFFFE2000)))
#define VICVectCntl7    (*(REG32 (0xFFFE2000)))
#define VICVectCntl8    (*(REG32 (0xFFFE2000)))
#define VICVectCntl9    (*(REG32 (0xFFFE2000)))
#define VICVectCntl10   (*(REG32 (0xFFFE2000)))
#define VICVectCntl11   (*(REG32 (0xFFFE2000)))
#define VICVectCntl12   (*(REG32 (0xFFFE2000)))
#define VICVectCntl13   (*(REG32 (0xFFFE2000)))
#define VICVectCntl14   (*(REG32 (0xFFFE2000)))
#define VICVectCntl15   (*(REG32 (0xFFFFF0BC))) */

#define IC_IRQ0_STATUS       (*(REG32 (0xFFFE2000))) //R-only
#define IC_IRQ0_RAWSTAT      (*(REG32 (0xFFFE2004))) //R-only
#define IC_IRQ0_ENABLESET    (*(REG32 (0xFFFE2008))) //RW
#define IC_IRQ0_ENABLECLR    (*(REG32 (0xFFFE200C))) //RW

#define IC_INT_SOFTSET_0     (*(REG32 (0xFFFE2010))) //RW
#define IC_INT_SOFTCLEAR_0   (*(REG32 (0xFFFE2014))) //RW

#define IC_FIRQ0_STATUS      (*(REG32 (0xFFFE2020)))
#define IC_FIRQ0_RAWSTAT     (*(REG32 (0xFFFE2024)))
#define IC_FIRQ0_ENABLESET   (*(REG32 (0xFFFE2028)))
#define IC_FIRQ0_ENABLECLR   (*(REG32 (0xFFFE202C)))

#define IC_IRQ1_STATUS       (*(REG32 (0xFFFE2040)))
#define IC_IRQ1_RAWSTAT      (*(REG32 (0xFFFE2044)))
#define IC_IRQ1_ENABLESET    (*(REG32 (0xFFFE2048)))
#define IC_IRQ1_ENABLECLR    (*(REG32 (0xFFFE204C)))

#define IC_INT_SOFTSET_1     (*(REG32 (0xFFFE2050)))
#define IC_INT_SOFTCLEAR_1   (*(REG32 (0xFFFE2054)))

#define IC_FIRQ1_STATUS      (*(REG32 (0xFFFE2060)))
#define IC_FIRQ1_RAWSTAT     (*(REG32 (0xFFFE2064)))
#define IC_FIRQ1_ENABLESET   (*(REG32 (0xFFFE2068)))
#define IC_FIRQ1_ENABLECLR   (*(REG32 (0xFFFE206C)))

#define IC_INT_SOFTSET_2     (*(REG32 (0xFFFE2090)))
#define IC_INT_SOFTCLEAR_2   (*(REG32 (0xFFFE2094)))

#define IC_INT_SOFTSET_3     (*(REG32 (0xFFFE20D0)))
#define IC_INT_SOFTCLEAR_3   (*(REG32 (0xFFFE20D4)))
//-------------------Backwards Compatability Begin--------------
#define VICVectAddr    (*(REG32 (0xFFFFFF40)))
#define VICVectAddr0    (*(REG32 (0xFFFFFF60)))
#define VICVectCntl0    (*(REG32 (0xFFFFFF80)))
#define VICIntEnable    (*(REG32 (0xFFFFFF10)))

//-------------------Backwards Compatability End--------------
#endif // storm_soc_basic_h




