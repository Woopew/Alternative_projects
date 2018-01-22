#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


void printBinary(unsigned short byte);
void clear_screen(int y);
void delay();
void printSpaces(int n);


int main(int argc, char **argv)
{
	unsigned short a = 0x0001, b = 0x8000;
	int scrollWidth = 50;
	int loopIter = 0;
	
	while(1)
	{
		clear_screen(50);
		usleep(2000);
		int scrollIter = loopIter % (2*scrollWidth);
		int pos = 5 + scrollWidth - abs(scrollWidth - scrollIter);
		printSpaces(pos);
		
		if((loopIter % 2) != 0){
			a = (a <= 0x0001) ? 0x8000 : a >> 1;
			b = (b == 0x8000) ? 0x0001 : b << 1;
		} 
		printBinary(a | b);
		printf("\n");
		usleep(40000);
		loopIter++;

		
	}
}

void printBinary(unsigned short byte)
{
    for(int i=15; i>=0; i--) 
	{
        int bit = (byte >> i) & 0x0001;
        printf("%d", bit);
    }
}
void delay()
{
	   int c, d;
 
   for ( c = 1 ; c <= 1000 ; c++ )
       for ( d = 1 ; d <= 32767 ; d++ )
       {}
}
void clear_screen(int y)
{
	for(int i = 0;i<y;i++)
	{
		printf("\n");
	}
}
void printSpaces(int n)
{
	for(int i=0; i < n; i++)
		printf(" ");
}