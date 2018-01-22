#include <stdio.h>
#include <stdlib.h>


void printBinary(unsigned char byte);
void clear_screen();
void delay();
void printSpaces(int n);


int main(int argc, char **argv)
{
	
	
	unsigned int one = 1, two = 128;
	while(1)
	{
		if(one == 128){
			for(int i = 7;i > 0;i--){
				one = one >> 1;
				two = two << 1;
				//printf("%d",one);
				clear_screen();
				printBinary(one);
				printBinary(two);
				delay();
			}
		}
		if(one == 1){
			for(int i = 7;i > 0;i--){
				one = one << 1;
				two = two >> 1;
				//printf("%d",one);
				clear_screen();
				printBinary(one);
				printBinary(two);
				delay();
			}
		}

		
	}
}

void printBinary(unsigned char byte)
{
    for(int i=7; i>=0; i--) 
	{
        int bit = (byte >> i) & 0x01;
        printf("%d", bit);
    }
}
void delay(){
	   int c, d;
 
   for ( c = 1 ; c <= 5000 ; c++ )
       for ( d = 1 ; d <= 32767 ; d++ )
       {}
}
void clear_screen(){
	for(int i = 0;i<30;i++){
		printf("\n");
	}
}
void printSpaces(int n){
	for(int i=0; i < n; i++){
		printf(" ");
	}
}