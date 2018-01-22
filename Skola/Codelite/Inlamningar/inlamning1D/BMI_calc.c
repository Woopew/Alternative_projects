/*
 *  File    : BMI_calc.c 
 *  Program : Calculates BMI from height and weight
 *  Author  : Victor Sandin
 *  Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	double mass=0, height=0, bmi=0;
	int a=1,b=1;
	
	printf("Räkna ut ditt BMI, avsluta med EOF (ctrl+d)\n\n");
	
	while(a==1 || b==1){
		
		printf("Hur lang ar du?(cm)\n");
		a = scanf("%lf", &height);
		if(a==0) break;
		printf("Hur mycket vager du?(kg)\n");
		b = scanf("%lf",&mass);
		if(b==0) break;
		
		bmi = mass/pow((height/100),2);
		printf("Din BMI ar: %lf\n\n",bmi);
	}
	
	printf("\n\nHejda snygging!\n");
	system("pause");
	return 0;
}
