#include<avr\io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void InitPWM()
{

	TCCR0 |= 1 << WGM00 | 1 << WGM01 | 1 << CS00 | 0 << CS01 | 1 << CS02 | 1 << COM01;
	DDRB |= 1 << PB3;
	

}
void InitPWM2()
{

	TCCR2 |= 1 << WGM20 | 1 << WGM21 | 1 << CS20 | 0 << CS21 | 1 << CS22 | 1 << COM21;
	DDRD |= 1 << PD7;
	

}

void SetPWMOutput(int duty)
{
	if(duty==0)
	{
		DDRB &= ~(1 << PB3);
	}
	else
	{
	OCR0 = duty;
	}
	DDRB |= (1 << PB3);
}
void SetPWMOutput2(int duty)
{
	if(duty==0)
	{
		DDRD &= ~(1 << PD7);
	}
	else
	{
	OCR2 = duty;
	}
	DDRD |= (1 << PD7);
}

void Wait()
{

	_delay_loop_2(10);

}

int main()
{
int wave1 = 0,xwave1 = 0, ywave1 = 90,wave2=0,xwave2=0,ywave2=90;
InitPWM();
InitPWM2();


while(1)
	{
	OCR0=0;OCR2=0;DDRD &= ~(1 << PD7);DDRB |= (1 << PB3);xwave1 = 0; ywave1 = 90;
	for(wave1=0;wave1<255;wave1=255*sin(0.0174533*(xwave1+1)))
		{
			xwave1++;
			SetPWMOutput(wave1);
			//Wait();
			OCR2=0;
		}
	for(wave1=255;wave1>0;wave1=255*sin(0.0174533*(ywave1-1)))
		{
			ywave1--;
			SetPWMOutput(wave1);
			//Wait();
			OCR2=0;
		}
		
	DDRD |= (1 << PD7);DDRB &= ~(1 << PB3);xwave2 = 0; ywave2 = 90;
	for(wave2=0;wave2<1;wave2=255*sin(0.0174533*(xwave2+1)))
		{
			xwave2++;
			SetPWMOutput2(wave2);
			//Wait();
			OCR0=0;
		}	
	for(wave2=1;wave2>0;wave2=255*sin(0.0174533*(ywave2-1)))
		{
			ywave2--;
			SetPWMOutput2(wave2);
			//Wait();
			OCR0=0;
		}

}}
