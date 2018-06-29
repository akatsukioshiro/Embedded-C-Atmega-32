#include<avr\io.h>
int main()
{
	TCCR2=1<<WGM20|1<<WGM21|0<<CS22|0<<CS21|1<<CS20|1<<COM21;
	TCCR0=1<<WGM00|1<<WGM01|0<<CS02|0<<CS01|1<<CS00|1<<COM01;
	DDRB|=1<<PB3;DDRD|=1<<PD7;
	int t=0,x=0;
	while(1)
	{
		int a=255,b=0,d,e=0,z;
		if(t==0){d=0;z=18;}else{d=90;z=-18;}
		while(a>b){(t==0)?(e=b):(e=a);e=255*sin(0.0174533*(d+=z));(x==0)?(OCR2=e):(OCR0=e);(t==0)?(b=e):(a=e);}++t;
		switch(t){case 2:{t=0;++x;}}switch(x){case 2:x=0;}
	}
}
