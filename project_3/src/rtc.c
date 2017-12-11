/**
 * @file rtc.c
 * @brief The implementation file for the rtc module
 *
 * This implementation file provides the function definitions for
 * implementing rtc module for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 7 December 2017
 *
 */

#include "rtc.h"


void RTC_CLKSRC_init(void)
{

	/* MCGIRCLK Slow Internal reference clock 32kHz */
	MCG_C1 |= MCG_C1_IRCLKEN_MASK;
	MCG_C2 |= MCG_C2_IRCS(0);

	/* Enable Port C Clock gating */
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;

	/* RTC CLock-In  PTC1 */
	PORTC_PCR1 |= PORT_PCR_MUX(0x1);

	/* Clock-out PTC5 */
	PORTC_PCR3 |= PORT_PCR_MUX(0x5);

	/* CLOCK-Out Select - MCGIRCLK */
	SIM_SOPT2 &= ~(SIM_SOPT2_CLKOUTSEL_MASK);
	SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0x4);

	/* 32kHz Clock source for RTC - RTC_CLKIN */
	SIM_SOPT1 &= ~(SIM_SOPT1_OSC32KSEL_MASK);
	SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x2);

}

void RTC_init(void)
{
	/* Enable RTC Clock gating */
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;

	/* S/W reset and SWR bit clear */
	RTC_CR = RTC_CR_SWR_MASK;
	RTC_CR &= ~RTC_CR_SWR_MASK;

	if(RTC_SR & RTC_SR_TIF_MASK)
	{
		RTC_TSR = 0x00000000;
	}

	/* adjust TCR after 1 second
	 * prescaler register overflows every 32768 clk cycles */
	RTC_TCR = (RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF));

	/* Enable timer seconds interrupt */
	RTC_IER |= RTC_IER_TSIE_MASK;

	NVIC_EnableIRQ(RTC_Seconds_IRQn);

	/* Enable the Timer counter */
	RTC_SR |= RTC_SR_TCE_MASK;

}

void RTC_Seconds_IRQHandler(void)
{
	//
}
