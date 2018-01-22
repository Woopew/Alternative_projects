/*
 *  File    : mean_value.c 
 *  Program : Mean value calculator
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a,b,c;
	double d;
	printf("Mata in 3 separata heltal\n");
	scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	
	d=(a+b+c)/3.0;
	
	printf("Medelvärdet av dina tal är: %lf \n\n", d);
	
	system("pause");
	return 0;
}
