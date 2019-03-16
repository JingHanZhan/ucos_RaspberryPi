#ifndef REGS_H_
#define REGS_H_

#define GPFSEL1 0x3F200004
#define GPSET0 0x3F20001C
#define GPCLR0 0x3F200028
#define GPPUD 0x3F200094
#define GPPUDCLK0 0x3F200098

#define AUX_ENABLES 0X3F215004
#define AUX_MU_IO_REG 0X3F215040
#define AUX_MU_IER_REG 0X3F215044
#define AUX_MU_IIR_REG 0X3F215048
#define AUX_MU_LCR_REG 0X3F21504C
#define AUX_MU_MCR_REG 0X3F215050
#define AUX_MU_LSR_REG 0X3F215054
#define AUX_MU_MSR_REG 0X3F215058
#define AUX_MU_SCRATCH 0X3F21505C
#define AUX_MU_CNTL_REG 0X3F215060
#define AUX_MU_STAT_REG 0X3F215064
#define AUX_MU_BAUD_REG 0X3F215068

// interrupt control regs
#define BASE_INTC (0x3F00B200)

typedef struct {
    unsigned long IRQBasic;  // Pending 0
    unsigned long Pending1;
    unsigned long Pending2;
    unsigned long FIQCtrl;
    unsigned long Enable1;
    unsigned long Enable2;
    unsigned long EnableBasic;
    unsigned long Disable1;
    unsigned long Disable2;
    unsigned long DisableBasic;
} INTC_REGS;

static volatile INTC_REGS *const intcRegs = (INTC_REGS *)(BASE_INTC);

// timer regs
#define portTIMER_BASE ((unsigned long)0x3F00B400)

typedef struct _BCM2835_TIMER_REGS {
    unsigned long LOD;
    unsigned long VAL;
    unsigned long CTL;
    unsigned long CLI;
    unsigned long RIS;
    unsigned long MIS;
    unsigned long RLD;
    unsigned long DIV;
    unsigned long CNT;
} TIMER_REGS;

static volatile TIMER_REGS *const timerRegs = (TIMER_REGS *)(portTIMER_BASE);

#endif /* REGS_H_ */
