#ifndef	_PHIDIAS_DRIVERS_IRQ_H_
#define	_PHIDIAS_DRIVERS_IRQ_H_

# include <memarea.h>

# if defined(IRQ_DRIVER_LAPIC)

# include <drivers/irq-lapic.h>

static inline void irq_setup(void) {
	irq_lapic_setup(core_memarea(MEMAREA_LAPIC), core_memarea(MEMAREA_IOAPIC));
}

static inline uint32_t irq_get_irq_raw(void) {
	return irq_lapic_get_irq_raw(core_memarea(MEMAREA_LAPIC), core_memarea(MEMAREA_IOAPIC));
}

static inline uint32_t irq_get_irq(uint32_t interrupt_number_raw) {
	return (interrupt_number_raw) & 0xff;
}

static inline void irq_ack_irq(uint32_t interrupt_number_raw) {
	irq_lapic_ack_irq(core_memarea(MEMAREA_LAPIC), core_memarea(MEMAREA_IOAPIC), interrupt_number_raw);
}

static inline void irq_disable_irq(uint32_t interrupt_number) {
	irq_lapic_disable_irq(core_memarea(MEMAREA_LAPIC), core_memarea(MEMAREA_IOAPIC), interrupt_number);
}

static inline void irq_raise_ipi(uint32_t target_cpu_number) {
	irq_lapic_raise_ipi(core_memarea(MEMAREA_LAPIC), target_cpu_number);
}

# elif defined(IRQ_DRIVER_MPCORE)

# include <drivers/irq-mpcore.h>

static inline void irq_setup(void) {
	irq_mpcore_setup(core_memarea(MEMAREA_MPCORE));
}

static inline uint32_t irq_get_irq_raw(void) {
	return irq_mpcore_get_irq_raw(core_memarea(MEMAREA_MPCORE));
}

static inline uint32_t irq_get_irq(uint32_t interrupt_number_raw) {
	return (interrupt_number_raw) & 0x3ff;
}

static inline void irq_ack_irq(uint32_t interrupt_number_raw) {
	irq_mpcore_ack_irq(core_memarea(MEMAREA_MPCORE), interrupt_number_raw);
}

static inline void irq_disable_irq(uint32_t interrupt_number) {
	irq_mpcore_disable_irq(core_memarea(MEMAREA_MPCORE), interrupt_number);
}

# elif defined(IRQ_DRIVER_BCM283X)

# include <drivers/irq-bcm283x.h>

static inline void irq_setup(void) {
	irq_bcm283x_setup(core_memarea(MEMAREA_IRQC), core_memarea(MEMAREA_MBOX));
}

static inline uint32_t irq_get_irq_raw(void) {
	return irq_bcm283x_get_irq_raw(core_memarea(MEMAREA_IRQC), core_memarea(MEMAREA_MBOX));
}

static inline uint32_t irq_get_irq(uint32_t interrupt_number_raw) {
	return (interrupt_number_raw) & 0x3ff;
}

static inline void irq_ack_irq(uint32_t interrupt_number_raw) {
	irq_bcm283x_ack_irq(core_memarea(MEMAREA_IRQC), interrupt_number_raw);
}

static inline void irq_disable_irq(uint32_t interrupt_number) {
	irq_bcm283x_disable_irq(core_memarea(MEMAREA_IRQC), interrupt_number);
}

# elif defined(IRQ_DRIVER_GIC)

# include <drivers/irq-gic.h>
#include <mmio.h>

static inline void irq_setup(void) {
	irq_gic_setup(core_memarea(MEMAREA_IRQC));
}

static int gic_route_irq(unsigned int irq, char level,
                         unsigned int cpu_mask, unsigned int priority)
{
    volatile unsigned char *bytereg;
    uint32_t cfg, edgebit;
    unsigned long flags;
    printf("cpu number %d\n\r", cpu_number);
    /* Disable interrupt */
    irq_gic_disable_irq(core_memarea(MEMAREA_IRQC), irq);
    printf(" irq_gic_disable_irq \n\r");
    /* Set edge / level */
    cfg = mmio_read32(core_memarea(MEMAREA_IRQC)->vaddr + GICV2_AREAOFFSET_DIST +
				GIC_DIST_CONFIG_BASE + irq / 16);

    edgebit = 2u << (2 * (irq % 16));
    if ( level )
        cfg &= ~edgebit;
    else
        cfg |= edgebit;
    mmio_write32(core_memarea(MEMAREA_IRQC)->vaddr + GICV2_AREAOFFSET_DIST +
				GIC_DIST_CONFIG_BASE + irq / 16, cfg);
    printf(" set edge \n\r");
    /* Set target CPU mask (RAZ/WI on uniprocessor) */
    bytereg = (unsigned char *)mmio_read32(core_memarea(MEMAREA_IRQC)->vaddr + GICV2_AREAOFFSET_DIST + GIC_DIST_TARGETS_BASE );
    bytereg[irq] = cpu_mask;
   printf(" target CPU mask  \n\r");
    /* Set priority */
    //bytereg = (unsigned char *)mmio_read32(core_memarea(MEMAREA_IRQC)->vaddr + GICV2_AREAOFFSET_DIST + GIC_DIST_PRIORITY_BASE);
    //bytereg[irq] = priority;

    irq_gic_enable_irq(core_memarea(MEMAREA_IRQC), irq);
    printf(" Set priority and enable \n\r");
    return 0;
}

static inline uint32_t irq_get_irq_raw(void) {
	return irq_gic_get_irq_raw(core_memarea(MEMAREA_IRQC));
}

static inline uint32_t irq_get_irq(uint32_t interrupt_number_raw) {
	return (interrupt_number_raw) & 0x3ff;
}

static inline void irq_ack_irq(uint32_t interrupt_number_raw) {
	irq_gic_ack_irq(core_memarea(MEMAREA_IRQC), interrupt_number_raw);
}

static inline void irq_disable_irq(uint32_t interrupt_number) {
	irq_gic_disable_irq(core_memarea(MEMAREA_IRQC), interrupt_number);
}

static inline void irq_raise_ipi(uint32_t target_cpu_number) {
	irq_gic_raise_ipi(core_memarea(MEMAREA_IRQC), target_cpu_number);
}

# elif defined(IRQ_DRIVER_PIC32)

# include <drivers/irq-pic32.h>

static inline void irq_setup(void) {
	irq_pic32_setup(core_memarea(MEMAREA_IRQ_PIC32));
}

static inline uint32_t irq_get_irq_raw(void) {
	return irq_pic32_get_irq_raw(core_memarea(MEMAREA_IRQ_PIC32));
}

static inline uint32_t irq_get_irq(uint32_t interrupt_number_raw) {
	return interrupt_number_raw;
}

static inline void irq_ack_irq(uint32_t interrupt_number_raw) {
	irq_pic32_ack_irq(core_memarea(MEMAREA_IRQ_PIC32), interrupt_number_raw);
}

static inline void irq_enable_irq(uint32_t interrupt_number, uint8_t prio, void *isr_ptr) {
	irq_pic32_enable_irq(core_memarea(MEMAREA_IRQ_PIC32), interrupt_number, prio, isr_ptr);
}

static inline void irq_disable_irq(uint32_t interrupt_number) {
	irq_pic32_disable_irq(core_memarea(MEMAREA_IRQ_PIC32), interrupt_number);
}

static inline void irq_raise_ipi(uint32_t target_cpu_number) {
	(void)target_cpu_number;
}

# else
# warning No irq driver selected!

static inline void irq_setup(void) {}
static inline uint32_t irq_get_irq_raw(void) { return 0x3ff; }
static inline uint32_t irq_get_irq(uint32_t interrupt_number_raw) { (void)interrupt_number_raw; return 0x3ff; }
static inline void irq_ack_irq(uint32_t interrupt_number_raw) { (void)interrupt_number_raw; }
static inline void irq_raise_ipi(uint32_t target_cpu_number) { (void)target_cpu_number; }

# endif

#endif
