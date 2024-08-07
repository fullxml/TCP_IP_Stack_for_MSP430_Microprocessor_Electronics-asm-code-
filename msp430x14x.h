/********************************************************************
*
* Standard register and bit definitions for the Texas Instruments
* MSP430 microcontroller.
*
* This file supports assembler and C development within the IAR
* Workbench environment for MSP430x14x devices.
*
* Texas Instruments, Version 1.1
*
********************************************************************/

#ifndef __msp430x14x
#define __msp430x14x

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                0x0001
#define BIT1                0x0002
#define BIT2                0x0004
#define BIT3                0x0008
#define BIT4                0x0010
#define BIT5                0x0020
#define BIT6                0x0040
#define BIT7                0x0080
#define BIT8                0x0100
#define BIT9                0x0200
#define BITA                0x0400
#define BITB                0x0800
#define BITC                0x1000
#define BITD                0x2000
#define BITE                0x4000
#define BITF                0x8000

/************************************************************
* STATUS REGISTER BITS
************************************************************/

#define C                   0x0001
#define Z                   0x0002
#define N                   0x0004
#define V                   0x0100
#define GIE                 0x0008
#define CPUOFF              0x0010
#define OSCOFF              0x0020
#define SCG0                0x0040
#define SCG1                0x0080

/* Low Power Modes coded with Bits 4-7 in SR */

#ifndef __IAR_SYSTEMS_ICC /* Begin #defines for assembler */
#define LPM0                CPUOFF
#define LPM1                SCG0+CPUOFF
#define LPM2                SCG1+CPUOFF
#define LPM3                SCG1+SCG0+CPUOFF
#define LPM4                SCG1+SCG0+OSCOFF+CPUOFF
/* End #defines for assembler */

#else /* Begin #defines for C */
#define LPM0_bits           CPUOFF
#define LPM1_bits           SCG0+CPUOFF
#define LPM2_bits           SCG1+CPUOFF
#define LPM3_bits           SCG1+SCG0+CPUOFF
#define LPM4_bits           SCG1+SCG0+OSCOFF+CPUOFF

#include "In430.h"

#define LPM0      _BIS_SR(LPM0_bits) /* Enter Low Power Mode 0 */
#define LPM0_EXIT _BIC_SR(LPM0_bits) /* Exit Low Power Mode 0 */
#define LPM1      _BIS_SR(LPM1_bits) /* Enter Low Power Mode 1 */
#define LPM1_EXIT _BIC_SR(LPM1_bits) /* Exit Low Power Mode 1 */
#define LPM2      _BIS_SR(LPM2_bits) /* Enter Low Power Mode 2 */
#define LPM2_EXIT _BIC_SR(LPM2_bits) /* Exit Low Power Mode 2 */
#define LPM3      _BIS_SR(LPM3_bits) /* Enter Low Power Mode 3 */
#define LPM3_EXIT _BIC_SR(LPM3_bits) /* Exit Low Power Mode 3 */
#define LPM4      _BIS_SR(LPM4_bits) /* Enter Low Power Mode 4 */
#define LPM4_EXIT _BIC_SR(LPM4_bits) /* Exit Low Power Mode 4 */
#endif /* End #defines for C */

/************************************************************
* PERIPHERAL FILE MAP
************************************************************/

/************************************************************
* SPECIAL FUNCTION REGISTER ADDRESSES + CONTROL BITS
************************************************************/

#define IE1_                0x0000  /* Interrupt Enable 1 */
sfrb    IE1               = IE1_;
#define WDTIE               0x01
#define OFIE                0x02
#define NMIIE               0x10
#define ACCVIE              0x20
#define URXIE0              0x40
#define UTXIE0              0x80

#define IFG1_               0x0002  /* Interrupt Flag 1 */
sfrb    IFG1              = IFG1_;
#define WDTIFG              0x01
#define OFIFG               0x02
#define NMIIFG              0x10
#define URXIFG0             0x40
#define UTXIFG0             0x80

#define ME1_                0x0004  /* Module Enable 1 */
sfrb    ME1               = ME1_;
#define URXE0               0x40
#define USPIE0              0x40
#define UTXE0               0x80

#define IE2_                0x0001  /* Interrupt Enable 2 */
sfrb    IE2               = IE2_;
#define URXIE1              0x10
#define UTXIE1              0x20

#define IFG2_               0x0003  /* Interrupt Flag 2 */
sfrb    IFG2              = IFG2_;
#define URXIFG1             0x10
#define UTXIFG1             0x20

#define ME2_                0x0005  /* Module Enable 2 */
sfrb    ME2               = ME2_;
#define URXE1               0x10
#define USPIE1              0x10
#define UTXE1               0x20

/************************************************************
* WATCHDOG TIMER
************************************************************/

#define WDTCTL_             0x0120  /* Watchdog Timer Control */
sfrw    WDTCTL            = WDTCTL_;
/* The bit names have been prefixed with "WDT" */
#define WDTIS0              0x0001
#define WDTIS1              0x0002
#define WDTSSEL             0x0004
#define WDTCNTCL            0x0008
#define WDTTMSEL            0x0010
#define WDTNMI              0x0020
#define WDTNMIES            0x0040
#define WDTHOLD             0x0080

#define WDTPW               0x5A00

/* WDT-interval times [1ms] coded with Bits 0-2 */
/* WDT is clocked by fMCLK (assumed 1MHz) */
#define WDT_MDLY_32         WDTPW+WDTTMSEL+WDTCNTCL                         /* 32ms interval (default) */
#define WDT_MDLY_8          WDTPW+WDTTMSEL+WDTCNTCL+WDTIS0                  /* 8ms     " */
#define WDT_MDLY_0_5        WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1                  /* 0.5ms   " */
#define WDT_MDLY_0_064      WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1+WDTIS0           /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ADLY_1000       WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL                 /* 1000ms  " */
#define WDT_ADLY_250        WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS0          /* 250ms   " */
#define WDT_ADLY_16         WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1          /* 16ms    " */
#define WDT_ADLY_1_9        WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0   /* 1.9ms   " */
/* Watchdog mode -> reset after expired time */
/* WDT is clocked by fMCLK (assumed 1MHz) */
#define WDT_MRST_32         WDTPW+WDTCNTCL                                  /* 32ms interval (default) */
#define WDT_MRST_8          WDTPW+WDTCNTCL+WDTIS0                           /* 8ms     " */
#define WDT_MRST_0_5        WDTPW+WDTCNTCL+WDTIS1                           /* 0.5ms   " */
#define WDT_MRST_0_064      WDTPW+WDTCNTCL+WDTIS1+WDTIS0                    /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ARST_1000       WDTPW+WDTCNTCL+WDTSSEL                          /* 1000ms  " */
#define WDT_ARST_250        WDTPW+WDTCNTCL+WDTSSEL+WDTIS0                   /* 250ms   " */
#define WDT_ARST_16         WDTPW+WDTCNTCL+WDTSSEL+WDTIS1                   /* 16ms    " */
#define WDT_ARST_1_9        WDTPW+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0            /* 1.9ms   " */

/* INTERRUPT CONTROL */
/* These two bits are defined in the Special Function Registers */
/* #define WDTIE               0x01 */
/* #define WDTIFG              0x01 */

/************************************************************
* HARDWARE MULTIPLIER
************************************************************/

#define MPY_                0x0130  /* Multiply Unsigned/Operand 1 */
sfrw    MPY               = MPY_;
#define MPYS_               0x0132  /* Multiply Signed/OPerand 1 */
sfrw    MPYS              = MPYS_;
#define MAC_                0x0134  /* Multiply Unsigned and Accumulate/Operand 1 */
sfrw    MAC               = MAC_;
#define MACS_               0x0136  /* Multiply Signed and Accumulate/Operand 1 */
sfrw    MACS              = MACS_;
#define OP2_                0x0138  /* Operand 2 */
sfrw    OP2               = OP2_;
#define RESLO_              0x013A  /* Result Low Word */
sfrw    RESLO             = RESLO_;
#define RESHI_              0x013C  /* Result High Word */
sfrw    RESHI             = RESHI_;
#define SUMEXT_             0x013E  /* Sum Extend */
const sfrw SUMEXT         = SUMEXT_;

/************************************************************
* DIGITAL I/O Port1/2
************************************************************/

#define P1IN_               0x0020  /* Port 1 Input */
const sfrb P1IN           = P1IN_;
#define P1OUT_              0x0021  /* Port 1 Output */
sfrb    P1OUT             = P1OUT_;
#define P1DIR_              0x0022  /* Port 1 Direction */
sfrb    P1DIR             = P1DIR_;
#define P1IFG_              0x0023  /* Port 1 Interrupt Flag */
sfrb    P1IFG             = P1IFG_;
#define P1IES_              0x0024  /* Port 1 Interrupt Edge Select */
sfrb    P1IES             = P1IES_;
#define P1IE_               0x0025  /* Port 1 Interrupt Enable */
sfrb    P1IE              = P1IE_;
#define P1SEL_              0x0026  /* Port 1 Selection */
sfrb    P1SEL             = P1SEL_;

#define P2IN_               0x0028  /* Port 2 Input */
const sfrb P2IN           = P2IN_;
#define P2OUT_              0x0029  /* Port 2 Output */
sfrb    P2OUT             = P2OUT_;
#define P2DIR_              0x002A  /* Port 2 Direction */
sfrb    P2DIR             = P2DIR_;
#define P2IFG_              0x002B  /* Port 2 Interrupt Flag */
sfrb    P2IFG             = P2IFG_;
#define P2IES_              0x002C  /* Port 2 Interrupt Edge Select */
sfrb    P2IES             = P2IES_;
#define P2IE_               0x002D  /* Port 2 Interrupt Enable */
sfrb    P2IE              = P2IE_;
#define P2SEL_              0x002E  /* Port 2 Selection */
sfrb    P2SEL             = P2SEL_;

/************************************************************
* DIGITAL I/O Port3/4
************************************************************/

#define P3IN_               0x0018  /* Port 3 Input */
const sfrb P3IN           = P3IN_;
#define P3OUT_              0x0019  /* Port 3 Output */
sfrb    P3OUT             = P3OUT_;
#define P3DIR_              0x001A  /* Port 3 Direction */
sfrb    P3DIR             = P3DIR_;
#define P3SEL_              0x001B  /* Port 3 Selection */
sfrb    P3SEL             = P3SEL_;

#define P4IN_               0x001C  /* Port 4 Input */
const sfrb P4IN           = P4IN_;
#define P4OUT_              0x001D  /* Port 4 Output */
sfrb    P4OUT             = P4OUT_;
#define P4DIR_              0x001E  /* Port 4 Direction */
sfrb    P4DIR             = P4DIR_;
#define P4SEL_              0x001F  /* Port 4 Selection */
sfrb    P4SEL             = P4SEL_;

/************************************************************
* DIGITAL I/O Port5/6
************************************************************/

#define P5IN_               0x0030  /* Port 5 Input */
const sfrb P5IN           = P5IN_;
#define P5OUT_              0x0031  /* Port 5 Output */
sfrb    P5OUT             = P5OUT_;
#define P5DIR_              0x0032  /* Port 5 Direction */
sfrb    P5DIR             = P5DIR_;
#define P5SEL_              0x0033  /* Port 5 Selection */
sfrb    P5SEL             = P5SEL_;

#define P6IN_               0x0034  /* Port 6 Input */
const sfrb P6IN           = P6IN_;
#define P6OUT_              0x0035  /* Port 6 Output */
sfrb    P6OUT             = P6OUT_;
#define P6DIR_              0x0036  /* Port 6 Direction */
sfrb    P6DIR             = P6DIR_;
#define P6SEL_              0x0037  /* Port 6 Selection */
sfrb    P6SEL             = P6SEL_;

/************************************************************
* USART
************************************************************/

#define PENA                0x80        /* UCTL */
#define PEV                 0x40
#define SPB                 0x20        /* to distinguish from stackpointer SP */
#define CHAR                0x10
#define LISTEN              0x08
#define SYNC                0x04
#define MM                  0x02
#define SWRST               0x01

#define CKPH                0x80        /* UTCTL */
#define CKPL                0x40
#define SSEL1               0x20
#define SSEL0               0x10
#define URXSE               0x08
#define TXWAKE              0x04
#define STC                 0x02
#define TXEPT               0x01

#define FE                  0x80        /* URCTL */
#define PE                  0x40
#define OE                  0x20
#define BRK                 0x10
#define URXEIE              0x08
#define URXWIE              0x04
#define RXWAKE              0x02
#define RXERR               0x01

/************************************************************
* UART 0/1
************************************************************/

#define U0CTL_              0x0070  /* UART 0 Control */
sfrb    U0CTL             = U0CTL_;
#define U0TCTL_             0x0071  /* UART 0 Transmit Control */
sfrb    U0TCTL            = U0TCTL_;
#define U0RCTL_             0x0072  /* UART 0 Receive Control */
sfrb    U0RCTL            = U0RCTL_;
#define U0MCTL_             0x0073  /* UART 0 Modulation Control */
sfrb    U0MCTL            = U0MCTL_;
#define U0BR0_              0x0074  /* UART 0 Baud Rate 0 */
sfrb    U0BR0             = U0BR0_;
#define U0BR1_              0x0075  /* UART 0 Baud Rate 1 */
sfrb    U0BR1             = U0BR1_;
#define U0RXBUF_            0x0076  /* UART 0 Receive Buffer */
const sfrb U0RXBUF        = U0RXBUF_;
#define U0TXBUF_            0x0077  /* UART 0 Transmit Buffer */
sfrb    U0TXBUF           = U0TXBUF_;

#define U1CTL_              0x0078  /* UART 1 Control */
sfrb    U1CTL             = U1CTL_;
#define U1TCTL_             0x0079  /* UART 1 Transmit Control */
sfrb    U1TCTL            = U1TCTL_;
#define U1RCTL_             0x007A  /* UART 1 Receive Control */
sfrb    U1RCTL            = U1RCTL_;
#define U1MCTL_             0x007B  /* UART 1 Modulation Control */
sfrb    U1MCTL            = U1MCTL_;
#define U1BR0_              0x007C  /* UART 1 Baud Rate 0 */
sfrb    U1BR0             = U1BR0_;
#define U1BR1_              0x007D  /* UART 1 Baud Rate 1 */
sfrb    U1BR1             = U1BR1_;
#define U1RXBUF_            0x007E  /* UART 1 Receive Buffer */
const sfrb U1RXBUF        = U1RXBUF_;
#define U1TXBUF_            0x007F  /* UART 1 Transmit Buffer */
sfrb    U1TXBUF           = U1TXBUF_;

/* Alternate register names */

#define UCTL0_              0x0070  /* UART 0 Control */
sfrb    UCTL0             = UCTL0_;
#define UTCTL0_             0x0071  /* UART 0 Transmit Control */
sfrb    UTCTL0            = UTCTL0_;
#define URCTL0_             0x0072  /* UART 0 Receive Control */
sfrb    URCTL0            = URCTL0_;
#define UMCTL0_             0x0073  /* UART 0 Modulation Control */
sfrb    UMCTL0            = UMCTL0_;
#define UBR00_              0x0074  /* UART 0 Baud Rate 0 */
sfrb    UBR00             = UBR00_;
#define UBR10_              0x0075  /* UART 0 Baud Rate 1 */
sfrb    UBR10             = UBR10_;
#define RXBUF0_             0x0076  /* UART 0 Receive Buffer */
const sfrb RXBUF0         = RXBUF0_;
#define TXBUF0_             0x0077  /* UART 0 Transmit Buffer */
sfrb    TXBUF0            = TXBUF0_;

#define UCTL1_              0x0078  /* UART 1 Control */
sfrb    UCTL1             = UCTL1_;
#define UTCTL1_             0x0079  /* UART 1 Transmit Control */
sfrb    UTCTL1            = UTCTL1_;
#define URCTL1_             0x007A  /* UART 1 Receive Control */
sfrb    URCTL1            = URCTL1_;
#define UMCTL1_             0x007B  /* UART 1 Modulation Control */
sfrb    UMCTL1            = UMCTL1_;
#define UBR01_              0x007C  /* UART 1 Baud Rate 0 */
sfrb    UBR01             = UBR01_;
#define UBR11_              0x007D  /* UART 1 Baud Rate 1 */
sfrb    UBR11             = UBR11_;
#define RXBUF1_             0x007E  /* UART 1 Receive Buffer */
const sfrb RXBUF1         = RXBUF1_;
#define TXBUF1_             0x007F  /* UART 1 Transmit Buffer */
sfrb    TXBUF1            = TXBUF1_;

#define UCTL_0_             0x0070  /* UART 0 Control */
sfrb    UCTL_0            = UCTL_0_;
#define UTCTL_0_            0x0071  /* UART 0 Transmit Control */
sfrb    UTCTL_0           = UTCTL_0_;
#define URCTL_0_            0x0072  /* UART 0 Receive Control */
sfrb    URCTL_0           = URCTL_0_;
#define UMCTL_0_            0x0073  /* UART 0 Modulation Control */
sfrb    UMCTL_0           = UMCTL_0_;
#define UBR0_0_             0x0074  /* UART 0 Baud Rate 0 */
sfrb    UBR0_0            = UBR0_0_;
#define UBR1_0_             0x0075  /* UART 0 Baud Rate 1 */
sfrb    UBR1_0            = UBR1_0_;
#define RXBUF_0_            0x0076  /* UART 0 Receive Buffer */
const sfrb RXBUF_0        = RXBUF_0_;
#define TXBUF_0_            0x0077  /* UART 0 Transmit Buffer */
sfrb    TXBUF_0           = TXBUF_0_;

#define UCTL_1_             0x0078  /* UART 1 Control */
sfrb    UCTL_1            = UCTL_1_;
#define UTCTL_1_            0x0079  /* UART 1 Transmit Control */
sfrb    UTCTL_1           = UTCTL_1_;
#define URCTL_1_            0x007A  /* UART 1 Receive Control */
sfrb    URCTL_1           = URCTL_1_;
#define UMCTL_1_            0x007B  /* UART 1 Modulation Control */
sfrb    UMCTL_1           = UMCTL_1_;
#define UBR0_1_             0x007C  /* UART 1 Baud Rate 0 */
sfrb    UBR0_1            = UBR0_1_;
#define UBR1_1_             0x007D  /* UART 1 Baud Rate 1 */
sfrb    UBR1_1            = UBR1_1_;
#define RXBUF_1_            0x007E  /* UART 1 Receive Buffer */
const sfrb RXBUF_1        = RXBUF_1_;
#define TXBUF_1_            0x007F  /* UART 1 Transmit Buffer */
sfrb    TXBUF_1           = TXBUF_1_;

/************************************************************
* Timer A
************************************************************/

#define TAIV_               0x012E  /* Timer A Interrupt Vector Word */
sfrw    TAIV              = TAIV_;
#define TACTL_              0x0160  /* Timer A Control */
sfrw    TACTL             = TACTL_;
#define CCTL0_              0x0162  /* Timer A Capture/Compare Control 0 */
sfrw    CCTL0             = CCTL0_;
#define CCTL1_              0x0164  /* Timer A Capture/Compare Control 1 */
sfrw    CCTL1             = CCTL1_;
#define CCTL2_              0x0166  /* Timer A Capture/Compare Control 2 */
sfrw    CCTL2             = CCTL2_;
#define TAR_                0x0170  /* Timer A */
sfrw    TAR               = TAR_;
#define CCR0_               0x0172  /* Timer A Capture/Compare 0 */
sfrw    CCR0              = CCR0_;
#define CCR1_               0x0174  /* Timer A Capture/Compare 1 */
sfrw    CCR1              = CCR1_;
#define CCR2_               0x0176  /* Timer A Capture/Compare 2 */
sfrw    CCR2              = CCR2_;

#define TASSEL2             0x0400        /* to distinguish from UART SSELx */
#define TASSEL1             0x0200
#define TASSEL0             0x0100
#define ID1                 0x0080
#define ID0                 0x0040
#define MC1                 0x0020
#define MC0                 0x0010
#define TACLR               0x0004
#define TAIE                0x0002
#define TAIFG               0x0001

#define MC_0                00*0x10
#define MC_1                01*0x10
#define MC_2                02*0x10
#define MC_3                03*0x10
#define ID_0                00*0x40
#define ID_1                01*0x40
#define ID_2                02*0x40
#define ID_3                03*0x40
#define TASSEL_0            00*0x100
#define TASSEL_1            01*0x100
#define TASSEL_2            02*0x100
#define TASSEL_3            03*0x100

#define CM1                 0x8000
#define CM0                 0x4000
#define CCIS1               0x2000
#define CCIS0               0x1000
#define SCS                 0x0800
#define SCCI                0x0400
#define CAP                 0x0100
#define OUTMOD2             0x0080
#define OUTMOD1             0x0040
#define OUTMOD0             0x0020
#define CCIE                0x0010
#define CCI                 0x0008
#define OUT                 0x0004
#define COV                 0x0002
#define CCIFG               0x0001

#define OUTMOD_0            00*0x20
#define OUTMOD_1            01*0x20
#define OUTMOD_2            02*0x20
#define OUTMOD_3            03*0x20
#define OUTMOD_4            04*0x20
#define OUTMOD_5            05*0x20
#define OUTMOD_6            06*0x20
#define OUTMOD_7            07*0x20
#define CCIS_0              00*0x1000
#define CCIS_1              01*0x1000
#define CCIS_2              02*0x1000
#define CCIS_3              03*0x1000
#define CM_0                00*0x4000
#define CM_1                01*0x4000
#define CM_2                02*0x4000
#define CM_3                03*0x4000

/************************************************************
* Timer B
************************************************************/

#define TBIV_               0x011E  /* Timer B Interrupt Vector Word */
sfrw    TBIV              = TBIV_;
#define TBCTL_              0x0180  /* Timer B Control */
sfrw    TBCTL             = TBCTL_;
#define TBCCTL0_            0x0182  /* Timer B Capture/Compare Control 0 */
sfrw    TBCCTL0           = TBCCTL0_;
#define TBCCTL1_            0x0184  /* Timer B Capture/Compare Control 1 */
sfrw    TBCCTL1           = TBCCTL1_;
#define TBCCTL2_            0x0186  /* Timer B Capture/Compare Control 2 */
sfrw    TBCCTL2           = TBCCTL2_;
#define TBCCTL3_            0x0188  /* Timer B Capture/Compare Control 3 */
sfrw    TBCCTL3           = TBCCTL3_;
#define TBCCTL4_            0x018A  /* Timer B Capture/Compare Control 4 */
sfrw    TBCCTL4           = TBCCTL4_;
#define TBCCTL5_            0x018C  /* Timer B Capture/Compare Control 5 */
sfrw    TBCCTL5           = TBCCTL5_;
#define TBCCTL6_            0x018E  /* Timer B Capture/Compare Control 6 */
sfrw    TBCCTL6           = TBCCTL6_;
#define TBR_                0x0190  /* Timer B */
sfrw    TBR               = TBR_;
#define TBCCR0_             0x0192  /* Timer B Capture/Compare 0 */
sfrw    TBCCR0            = TBCCR0_;
#define TBCCR1_             0x0194  /* Timer B Capture/Compare 1 */
sfrw    TBCCR1            = TBCCR1_;
#define TBCCR2_             0x0196  /* Timer B Capture/Compare 2 */
sfrw    TBCCR2            = TBCCR2_;
#define TBCCR3_             0x0198  /* Timer B Capture/Compare 3 */
sfrw    TBCCR3            = TBCCR3_;
#define TBCCR4_             0x019A  /* Timer B Capture/Compare 4 */
sfrw    TBCCR4            = TBCCR4_;
#define TBCCR5_             0x019C  /* Timer B Capture/Compare 5 */
sfrw    TBCCR5            = TBCCR5_;
#define TBCCR6_             0x019E  /* Timer B Capture/Compare 6 */
sfrw    TBCCR6            = TBCCR6_;

#define SHR1                0x4000
#define SHR0                0x2000
#define CNTL1               0x1000
#define CNTL0               0x0800
#define TBSSEL2             0x0400
#define TBSSEL1             0x0200
#define TBSSEL0             0x0100
#define TBCLR               0x0004
#define TBIE                0x0002
#define TBIFG               0x0001

#define TBSSEL_0            00*0x0100
#define TBSSEL_1            01*0x0100
#define TBSSEL_2            02*0x0100
#define TBSSEL_3            03*0x0100
#define CNTL_0              00*0x0800
#define CNTL_1              01*0x0800
#define CNTL_2              02*0x0800
#define CNTL_3              03*0x0800
#define SHR_0               00*0x2000
#define SHR_1               01*0x2000
#define SHR_2               02*0x2000
#define SHR_3               03*0x2000

#define SLSHR1              0x0400
#define SLSHR0              0x0200

#define SLSHR_0             00*0x0200
#define SLSHR_1             01*0x0200
#define SLSHR_2             02*0x0200
#define SLSHR_3             03*0x0200

/************************************************************
* Basic Clock Module
************************************************************/

#define DCOCTL_             0x0056  /* DCO Clock Frequency Control */
sfrb    DCOCTL            = DCOCTL_;
#define BCSCTL1_            0x0057  /* Basic Clock System Control 1 */
sfrb    BCSCTL1           = BCSCTL1_;
#define BCSCTL2_            0x0058  /* Basic Clock System Control 2 */
sfrb    BCSCTL2           = BCSCTL2_;

#define MOD0                0x01
#define MOD1                0x02
#define MOD2                0x04
#define MOD3                0x08
#define MOD4                0x10
#define DCO0                0x20
#define DCO1                0x40
#define DCO2                0x80

#define RSEL0               0x01
#define RSEL1               0x02
#define RSEL2               0x04
#define XT5V                0x08
#define DIVA0               0x10
#define DIVA1               0x20
#define XTS                 0x40
#define XTOFF               0x80

#define DCOR                0x01
#define DIVS0               0x02
#define DIVS1               0x04
#define SELS                0x08
#define DIVM0               0x10
#define DIVM1               0x20
#define SELM0               0x40
#define SELM1               0x80

/*************************************************************
* Flash Memory
*************************************************************/

#define FCTL1_              0x0128  /* FLASH Control 1 */
sfrw    FCTL1             = FCTL1_;
#define FCTL2_              0x012A  /* FLASH Control 2 */
sfrw    FCTL2             = FCTL2_;
#define FCTL3_              0x012C  /* FLASH Control 3 */
sfrw    FCTL3             = FCTL3_;

#define FRKEY               0x9600
#define FWKEY               0xA500
#define FXKEY               0x3300        /* for use with XOR instruction */

#define ERASE               0x0002
#define MERAS               0x0004
#define WRT                 0x0040
#define SEGWRT              0x0080

#define FN0                 0x0001
#define FN1                 0x0002
#define FN2                 0x0004
#define FN3                 0x0008
#define FN4                 0x0010
#define FN5                 0x0020
#define FSSEL0              0x0040        /* to distinguish from UART SSELx */
#define FSSEL1              0x0080

#define BUSY                0x0001
#define KEYV                0x0002
#define ACCVIFG             0x0004
#define WAIT                0x0008
#define LOCK                0x0010
#define EMEX                0x0020

/************************************************************
* Comparator A
************************************************************/

#define CACTL1_             0x0059  /* Comparator A Control 1 */
sfrb    CACTL1            = CACTL1_;
#define CACTL2_             0x005A  /* Comparator A Control 2 */
sfrb    CACTL2            = CACTL2_;
#define CAPD_               0x005B  /* Comparator A Port Disable */
sfrb    CAPD              = CAPD_;

#define CAIFG               0x01
#define CAIE                0x02
#define CAIES               0x04
#define CAON                0x08
#define CAREF0              0x10
#define CAREF1              0x20
#define CARSEL              0x40
#define CAEX                0x80

#define CAOUT               0x01
#define CAF                 0x02
#define P2CA0               0x04
#define P2CA1               0x08
#define CACTL24             0x10
#define CACTL25             0x20
#define CACTL26             0x40
#define CACTL27             0x80

#define CAPD0               0x01
#define CAPD1               0x02
#define CAPD2               0x04
#define CAPD3               0x08
#define CAPD4               0x10
#define CAPD5               0x20
#define CAPD6               0x40
#define CAPD7               0x80

/************************************************************
* ADC12
************************************************************/

#define ADC12CTL0_          0x01A0  /* ADC12 Control 0 */
sfrw    ADC12CTL0         = ADC12CTL0_;
#define ADC12CTL1_          0x01A2  /* ADC12 Control 1 */
sfrw    ADC12CTL1         = ADC12CTL1_;
#define ADC12IFG_           0x01A4  /* ADC12 Interrupt Flag */
sfrw    ADC12IFG          = ADC12IFG_;
#define ADC12IE_            0x01A6  /* ADC12 Interrupt Enable */
sfrw    ADC12IE           = ADC12IE_;
#define ADC12IV_            0x01A8  /* ADC12 Interrupt Vector Word */
sfrw    ADC12IV           = ADC12IV_;

#define ADC12MEM_           0x0140  /* ADC12 Conversion Memory */
#ifndef __IAR_SYSTEMS_ICC
#define ADC12MEM            ADC12MEM_ /* ADC12 Conversion Memory (for assembler) */
#else
#define ADC12MEM            ((int*) ADC12MEM_) /* ADC12 Conversion Memory (for C) */
#endif
#define ADC12MEM0_          ADC12MEM_ /* ADC12 Conversion Memory 0 */
sfrw    ADC12MEM0         = ADC12MEM0_;
#define ADC12MEM1_          0x0142  /* ADC12 Conversion Memory 1 */
sfrw    ADC12MEM1         = ADC12MEM1_;
#define ADC12MEM2_          0x0144  /* ADC12 Conversion Memory 2 */
sfrw    ADC12MEM2         = ADC12MEM2_;
#define ADC12MEM3_          0x0146  /* ADC12 Conversion Memory 3 */
sfrw    ADC12MEM3         = ADC12MEM3_;
#define ADC12MEM4_          0x0148  /* ADC12 Conversion Memory 4 */
sfrw    ADC12MEM4         = ADC12MEM4_;
#define ADC12MEM5_          0x014A  /* ADC12 Conversion Memory 5 */
sfrw    ADC12MEM5         = ADC12MEM5_;
#define ADC12MEM6_          0x014C  /* ADC12 Conversion Memory 6 */
sfrw    ADC12MEM6         = ADC12MEM6_;
#define ADC12MEM7_          0x014E  /* ADC12 Conversion Memory 7 */
sfrw    ADC12MEM7         = ADC12MEM7_;
#define ADC12MEM8_          0x0150  /* ADC12 Conversion Memory 8 */
sfrw    ADC12MEM8         = ADC12MEM8_;
#define ADC12MEM9_          0x0152  /* ADC12 Conversion Memory 9 */
sfrw    ADC12MEM9         = ADC12MEM9_;
#define ADC12MEM10_         0x0154  /* ADC12 Conversion Memory 10 */
sfrw    ADC12MEM10        = ADC12MEM10_;
#define ADC12MEM11_         0x0156  /* ADC12 Conversion Memory 11 */
sfrw    ADC12MEM11        = ADC12MEM11_;
#define ADC12MEM12_         0x0158  /* ADC12 Conversion Memory 12 */
sfrw    ADC12MEM12        = ADC12MEM12_;
#define ADC12MEM13_         0x015A  /* ADC12 Conversion Memory 13 */
sfrw    ADC12MEM13        = ADC12MEM13_;
#define ADC12MEM14_         0x015C  /* ADC12 Conversion Memory 14 */
sfrw    ADC12MEM14        = ADC12MEM14_;
#define ADC12MEM15_         0x015E  /* ADC12 Conversion Memory 15 */
sfrw    ADC12MEM15        = ADC12MEM15_;

#define ADC12MCTL_          0x0080  /* ADC12 Memory Control */
#ifndef __IAR_SYSTEMS_ICC
#define ADC12MCTL           ADC12MCTL_ /* ADC12 Memory Control (for assembler) */
#else
#define ADC12MCTL           ((char*) ADC12MCTL_) /* ADC12 Memory Control (for C) */
#endif
#define ADC12MCTL0_         ADC12MCTL_ /* ADC12 Memory Control 0 */
sfrb    ADC12MCTL0        = ADC12MCTL0_;
#define ADC12MCTL1_         0x0081  /* ADC12 Memory Control 1 */
sfrb    ADC12MCTL1        = ADC12MCTL1_;
#define ADC12MCTL2_         0x0082  /* ADC12 Memory Control 2 */
sfrb    ADC12MCTL2        = ADC12MCTL2_;
#define ADC12MCTL3_         0x0083  /* ADC12 Memory Control 3 */
sfrb    ADC12MCTL3        = ADC12MCTL3_;
#define ADC12MCTL4_         0x0084  /* ADC12 Memory Control 4 */
sfrb    ADC12MCTL4        = ADC12MCTL4_;
#define ADC12MCTL5_         0x0085  /* ADC12 Memory Control 5 */
sfrb    ADC12MCTL5        = ADC12MCTL5_;
#define ADC12MCTL6_         0x0086  /* ADC12 Memory Control 6 */
sfrb    ADC12MCTL6        = ADC12MCTL6_;
#define ADC12MCTL7_         0x0087  /* ADC12 Memory Control 7 */
sfrb    ADC12MCTL7        = ADC12MCTL7_;
#define ADC12MCTL8_         0x0088  /* ADC12 Memory Control 8 */
sfrb    ADC12MCTL8        = ADC12MCTL8_;
#define ADC12MCTL9_         0x0089  /* ADC12 Memory Control 9 */
sfrb    ADC12MCTL9        = ADC12MCTL9_;
#define ADC12MCTL10_        0x008A  /* ADC12 Memory Control 10 */
sfrb    ADC12MCTL10       = ADC12MCTL10_;
#define ADC12MCTL11_        0x008B  /* ADC12 Memory Control 11 */
sfrb    ADC12MCTL11       = ADC12MCTL11_;
#define ADC12MCTL12_        0x008C  /* ADC12 Memory Control 12 */
sfrb    ADC12MCTL12       = ADC12MCTL12_;
#define ADC12MCTL13_        0x008D  /* ADC12 Memory Control 13 */
sfrb    ADC12MCTL13       = ADC12MCTL13_;
#define ADC12MCTL14_        0x008E  /* ADC12 Memory Control 14 */
sfrb    ADC12MCTL14       = ADC12MCTL14_;
#define ADC12MCTL15_        0x008F  /* ADC12 Memory Control 15 */
sfrb    ADC12MCTL15       = ADC12MCTL15_;

#define ADC12SC             0x001 /* ADC12CTL0 */
#define ENC                 0x002
#define ADC12TOVIE          0x004
#define ADC12OVIE           0x008
#define ADC12ON             0x010
#define REFON               0x020
#define REF2_5V             0x040
#define MSH                 0x080

#define SHT0_0              00*0x100
#define SHT0_1              01*0x100
#define SHT0_2              02*0x100
#define SHT0_3              03*0x100
#define SHT0_4              04*0x100
#define SHT0_5              05*0x100
#define SHT0_6              06*0x100
#define SHT0_7              07*0x100
#define SHT0_8              08*0x100
#define SHT0_9              09*0x100
#define SHT0_10             10*0x100
#define SHT0_11             11*0x100
#define SHT0_12             12*0x100
#define SHT0_13             13*0x100
#define SHT0_14             14*0x100
#define SHT0_15             15*0x100

#define SHT1_0              00*0x1000
#define SHT1_1              01*0x1000
#define SHT1_2              02*0x1000
#define SHT1_3              03*0x1000
#define SHT1_4              04*0x1000
#define SHT1_5              05*0x1000
#define SHT1_6              06*0x1000
#define SHT1_7              07*0x1000
#define SHT1_8              08*0x1000
#define SHT1_9              09*0x1000
#define SHT1_10             10*0x1000
#define SHT1_11             11*0x1000
#define SHT1_12             12*0x1000
#define SHT1_13             13*0x1000
#define SHT1_14             14*0x1000
#define SHT1_15             15*0x1000

#define ADC12BUSY           0x0001 /* ADC12CTL1 */
#define CONSEQ_0            00*2
#define CONSEQ_1            01*2
#define CONSEQ_2            02*2
#define CONSEQ_3            03*2
#define ADC12SSEL_0         00*8
#define ADC12SSEL_1         01*8
#define ADC12SSEL_2         02*8
#define ADC12SSEL_3         03*8
#define ADC12DIV_0          00*0x20
#define ADC12DIV_1          01*0x20
#define ADC12DIV_2          02*0x20
#define ADC12DIV_3          03*0x20
#define ADC12DIV_4          04*0x20
#define ADC12DIV_5          05*0x20
#define ADC12DIV_6          06*0x20
#define ADC12DIV_7          07*0x20
#define ISSH                0x0100
#define SHP                 0x0200
#define SHS_0               00*0x400
#define SHS_1               01*0x400
#define SHS_2               02*0x400
#define SHS_3               03*0x400

#define CSTARTADD_0         00*0x1000
#define CSTARTADD_1         01*0x1000
#define CSTARTADD_2         02*0x1000
#define CSTARTADD_3         03*0x1000
#define CSTARTADD_4         04*0x1000
#define CSTARTADD_5         05*0x1000
#define CSTARTADD_6         06*0x1000
#define CSTARTADD_7         07*0x1000
#define CSTARTADD_8         08*0x1000
#define CSTARTADD_9         09*0x1000
#define CSTARTADD_10        10*0x1000
#define CSTARTADD_11        11*0x1000
#define CSTARTADD_12        12*0x1000
#define CSTARTADD_13        13*0x1000
#define CSTARTADD_14        14*0x1000
#define CSTARTADD_15        15*0x1000

#define INCH_0              00 /* ADC12CTLx */
#define INCH_1              01
#define INCH_2              02
#define INCH_3              03
#define INCH_4              04
#define INCH_5              05
#define INCH_6              06
#define INCH_7              07
#define INCH_8              08
#define INCH_9              09
#define INCH_10             10
#define INCH_11             11
#define INCH_12             12
#define INCH_13             13
#define INCH_14             14
#define INCH_15             15

#define SREF_0              00*0x10
#define SREF_1              01*0x10
#define SREF_2              02*0x10
#define SREF_3              03*0x10
#define SREF_4              04*0x10
#define SREF_5              05*0x10
#define SREF_6              06*0x10
#define SREF_7              07*0x10
#define EOS                 0x80

/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#define PORT2_VECTOR        1 * 2  /* 0xFFE2 Port 2 */
#define UART1TX_VECTOR      2 * 2  /* 0xFFE4 UART 1 Transmit */
#define UART1RX_VECTOR      3 * 2  /* 0xFFE6 UART 1 Receive */
#define PORT1_VECTOR        4 * 2  /* 0xFFE8 Port 1 */
#define TIMERA1_VECTOR      5 * 2  /* 0xFFEA Timer A CC1-2, TA */
#define TIMERA0_VECTOR      6 * 2  /* 0xFFEC Timer A CC0 */
#define ADC_VECTOR          7 * 2  /* 0xFFEE ADC */
#define UART0TX_VECTOR      8 * 2  /* 0xFFF0 UART 0 Transmit */
#define UART0RX_VECTOR      9 * 2  /* 0xFFF2 UART 0 Receive */
#define WDT_VECTOR          10 * 2 /* 0xFFF4 Watchdog Timer */
#define COMPARATORA_VECTOR  11 * 2 /* 0xFFF6 Comparator A */
#define TIMERB1_VECTOR      12 * 2 /* 0xFFF8 Timer B 1-7 */
#define TIMERB0_VECTOR      13 * 2 /* 0xFFFA Timer B 0 */
#define NMI_VECTOR          14 * 2 /* 0xFFFC Non-maskable */
#define RESET_VECTOR        15 * 2 /* 0xFFFE Reset [Highest Priority] */

/************************************************************
* End of Modules
************************************************************/

#endif /* #ifndef __msp430x14x */

