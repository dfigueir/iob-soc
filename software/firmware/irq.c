/*!
 *	@file	irq.c
 *  @brief	Interrupt handler
 */


// Includes

#include "irq.h"
#include "printf.h"
#include "iob_timer.h"



// Constants

#define TIMER_INTERRUPT 0x80000000



// External function definitions

uint32_t *irq(uint32_t *regs, uint32_t irqs)
{
	static uint32_t timer_irq_count = 0;
	int32_t time = 0;

	if ((irqs & TIMER_INTERRUPT) != 0) {
		printf("Timer interrupt %u\n", timer_irq_count);
		timer_irq_count++;
		timer_set_interrupt_period(100000000);
	}

	return regs;
}

// EOF
