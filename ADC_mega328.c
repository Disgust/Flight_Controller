#include "ADC_mega328.h"


 adcInit(uint8_t adc_psc, uint8_t refer, uint8_t left, uint8_t sleepMode)
{
	ADCSRA= 0; // Used for proper reinit being possible
	if (adc_psc <= 0x07)
	{
		ADCSRA|= (adc_psc << ADPS0);
	}
	if (refer <= 0x03)
	{
		ADMUX|= (refer << REFS0);
	}
	if (left)
	{
		BIT_set(ADMUX, ADLAR);
	}
	BIT_set(ADCSRA, ADEN); // Enable adc unit
	BIT_set(ADCSRA, ADIE); // ADC conversion complete interrupt enable
	if (sleepMode)
	{
		SMCR|= (0b001 << SM0);
	} 
	else
	{
		SMCR&= ~(0b001 << SM0);
	}
}

adcDigInDisable(uint8_t didb) {
	DIDR0|= (1 << didb);
}

 adcStart(adc_t * dat)
{
	dat->state= 0;
	BIT_set(ADCSRA, ADSC); // Start conversion
}

 adcStartAndSleep(adc_t * dat)
 {
	 BIT_set(SMCR, SE);
	 adcStart(dat);
	 asm("sleep");
 }

adcGetDataAndWakeUp(adc_t * result)
{
	BIT_clear(SMCR, SE);
	adcGetData(result);
}

 adcSelectChannel(uint8_t adc_msk)
{
	ADMUX&= 0xF0; // Clear previous channel settings
	ADMUX&= adc_msk;
}

adcGetData(adc_t * result)
{
	if(BIT_read(ADMUX, ADLAR)) {
		result->value= (ADC >> 6);
	}
	else {
		result->value= ADC;
	}
	result->state= 1;
}