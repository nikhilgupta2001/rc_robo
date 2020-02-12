#include<stdio.h> 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/sfr_defs.h>
#define ubrr 51
void initialise ()                                   //initializing UART
{
	UBRRH = (unsigned char)(ubrr>>8);                //set baut rate = 9600
	UBRRL = (unsigned char)ubrr;
	UCSRB = (1<<RXEN)| (1<<TXEN) ;                   // enabling receiver and transmitor
	UCSRC = (3<<UCSZ0);                              //asynchronous and 1 stop bits and 8bit data
	
}

void letter(unsigned char x)                          //send letter
{
	while(!((UCSRA) & (1<<UDRE)))                    //waiting for buffer to get empty
	;
	UDR=x;                                           //transfer data from x to udr

}


	int main()
	{
		initialise();
		while (1)
		{
		 if (bit_is_set(PINA,0))
			
			{
				letter ("f");
			}
			
	else if (bit_is_set(PINA,4))
			
			{
				letter ("d");
			}
		
		else if (bit_is_set(PINA,6))
		  
		  {
			  letter ("r");
		  }
		  
		   else if(bit_is_set(PINA,2))
		   
		  
		  {
			  letter ("l");
		  }
		}
		return 0;
		
	}

