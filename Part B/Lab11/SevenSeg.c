#include <LPC21XX.h>


unsigned int delay, count=0, Switchcount=0;
 
unsigned int Disp[16]={0x003F0000, 0x00060000, 0x005B0000, 0x004F0000, 0x00660000,0x006D0000,
					   0x007D0000, 0x00070000, 0x007F0000, 0x006F0000, 0x00770000,0x007C0000,
					   0x00390000, 0x005E0000, 0x00790000, 0x00710000 };


int main (void)
{
	  
	PINSEL1 = 0x00000000;
	IO0DIR  = 0xF0FF0000;
	
	
	while(1)
	{
		IO0SET = 0xf0000000;		 	// select all digits
		IO0CLR = 0x00FF0000;		 	// clear the data lines to 7-segment displays
		
		
		for(delay=0;delay<100;delay++); // delay  
		IO0SET = Disp[Switchcount];	   	// get the 7-segment display value from the array	
		for(delay=0;delay<1000000;delay++);// delay 
           
				
		
				Switchcount++;
				if(Switchcount == 16)	// 0 to F has been displayed ? go back to 0
			    {
				   Switchcount = 0;
				
			    }
	}
}	




