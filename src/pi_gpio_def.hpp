#ifndef _PI_GENEREIC_HPP
#define _PI_GENEREIC_HPP

#define	FSEL_ALT1		0b101
#define	FSEL_ALT2		0b110
#define	FSEL_ALT3		0b111
#define	FSEL_ALT4		0b011
#define	FSEL_ALT5		0b010

// Access from ARM Running Linux
//	Take from Gert/Doms code.

#define BCM2708_PERI_BASE	               0x20000000
#define GPIO_PADS		(BCM2708_PERI_BASE + 0x100000)
#define CLOCK_BASE		(BCM2708_PERI_BASE + 0x101000)
#define GPIO_BASE		(BCM2708_PERI_BASE + 0x200000)
#define GPIO_TIMER		(BCM2708_PERI_BASE + 0x00B000)
#define GPIO_PWM		(BCM2708_PERI_BASE + 0x20C000)

#define	PAGE_SIZE		(4*1024)
#define	BLOCK_SIZE		(4*1024)

// PWM
#define	PWM_CONTROL     0
#define	PWM_STATUS      1
#define	PWM0_RANGE      4
#define	PWM0_DATA       5
#define	PWM1_RANGE      8
#define	PWM1_DATA       9

#define	PWMCLK_CNTL	    40
#define	PWMCLK_DIV	    41

#define	PWM1_MS_MODE    0x8000  // Run in MS mode
#define	PWM1_USEFIFO    0x2000  // Data from FIFO
#define	PWM1_REVPOLAR   0x1000  // Reverse polarity
#define	PWM1_OFFSTATE   0x0800  // Ouput Off state
#define	PWM1_REPEATFF   0x0400  // Repeat last value if FIFO empty
#define	PWM1_SERIAL     0x0200  // Run in serial mode
#define	PWM1_ENABLE     0x0100  // Channel Enable

#define	PWM0_MS_MODE    0x0080  // Run in MS mode
#define	PWM0_USEFIFO    0x0020  // Data from FIFO
#define	PWM0_REVPOLAR   0x0010  // Reverse polarity
#define	PWM0_OFFSTATE   0x0008  // Ouput Off state
#define	PWM0_REPEATFF   0x0004  // Repeat last value if FIFO empty
#define	PWM0_SERIAL     0x0002  // Run in serial mode
#define	PWM0_ENABLE     0x0001  // Channel Enable

// Timer
#define	TIMER_LOAD	    (0x400 >> 2)
#define	TIMER_VALUE	    (0x404 >> 2)
#define	TIMER_CONTROL	(0x408 >> 2)
#define	TIMER_IRQ_CLR	(0x40C >> 2)
#define	TIMER_IRQ_RAW	(0x410 >> 2)
#define	TIMER_IRQ_MASK	(0x414 >> 2)
#define	TIMER_RELOAD	(0x418 >> 2)
#define	TIMER_PRE_DIV	(0x41C >> 2)
#define	TIMER_COUNTER	(0x420 >> 2)

#endif
