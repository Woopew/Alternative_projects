#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBinary(unsigned char byte);
void printShort(unsigned int byte);
void printInt(unsigned int byte);
void binaryToDec(char str[]);

int main(int argc, char **argv)
{
	
	/*
	signed char x = 27;
	printBinary(x);
	printf("%d\n",x);
	x ^= 0xff;
	printf("%d\n",x);
	printBinary(x);
	x++;
	printf("%d\n",x);
	printBinary(x);
	*/
	
	
	/*-------------------------------------------------------------------------------
	unsigned int byte = 97;
	int tal = 0x97;
	char str[] = "10010010";
	
		printf("byte: dec 97\n");
	printf("0x%x\n", byte);
	printBinary(byte);
	
		printf("\ntal: hex 97\n");
	
	printBinary(tal);
	printf("0x%x\n", tal);
	
		printf("\nstr: bin \"10010010\"\n");
		
	binaryToDec(str);
	*/
	/*
	if (byte < pow(2,8))
		printBinary(byte);
	else if (byte < pow(2,16))
		printShort(byte);
	else
		printInt(byte);
	*/
	
	/*-------------------------------------------------------------------------------*/
	
	/*-------------------------------------------------------------------------------
	unsigned char byte = 128;
	printBinary(byte); printf("\n");
	byte |= (1<<1 | 1<<3 | 1<<5);
	printBinary(byte); printf("\n");
	printf("%d\n", byte);
	-------------------------------------------------------------------------------*/
	
	
	
	//printf("%x\n", tal);
	//printBinary(tal);
	
	
	
	
	printf("\n");
	system("pause");
	return 0;
}

void printBinary(unsigned char byte)
{
    for(int i=7; i>=0; i--) 
	{
        int bit = (byte >> i) & 0x01;
        printf("%d", bit);
    }
	printf("\n");
}
void printShort(unsigned int byte)
{
    for(int i=15; i>=0; i--) 
	{
        int bit = (byte >> i) & 0x01;
        printf("%d", bit);
    }
	printf("\n");
}
void printInt(unsigned int byte)
{
    for(int i=31; i>=0; i--)
	{
        int bit = (byte >> i) & 0x01;
        printf("%d", bit);
    }
	printf("\n");
}
void binaryToDec(char str[])
{
	unsigned char byte = 0;
	for(int i=0;i<8;i++)
	{
		if(str[i] == '1')
			byte |= (1<<(7-i));
	}
	printf("%d\n", byte);
	printf("0x%x\n", byte);
}