#include <LPC21xx.h>

int count=0,sinevalue,value;
unsigned char sine_tab[49]=
      { 0x80,0x90,0xA1,0xB1,0xC0,0xCD,0xDA,0xE5,0xEE,0xF6,0xFB,0xFE,
        0xFF,0xFE,0xFB,0xF6,0xEE,0xE5,0xDA,0xCD,0xC0,0xB1,0xA1,0x90,
        0x80,0x70,0x5F,0x4F,0x40,0x33,0x26,0x1B,0x12,0x0A,0x05,0x02,
        0x00,0x02,0x05,0x0A,0x12,0x1B,0x26,0x33,0x40,0x4F,0x5F,0x70,0x80};

int main(void)
{
	PINSEL0 = 0x00000000 ;						// Configure P0.0 to P0.15 as GPIO
    IO0DIR  = 0x00FF0000 ;
 
	count = 0;
	while(1)
	{
		for(count=0;count<48;count++)
		{
			sinevalue = sine_tab[count];		//+0X10 ;
			value= 0x00FF0000 & (sinevalue << 16);
			IO0PIN = value;
		}
	}
}

 
    
 


