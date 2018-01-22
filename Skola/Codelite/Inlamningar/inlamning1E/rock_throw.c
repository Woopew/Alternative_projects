/*
 *  File    : rock_throw.c 
 *  Program : "Kastparabel"- calculator
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592
#define G 9.81

int main()
{
	double v,a,a_rad;
	printf("Nu raknar vi kastparabel pa liten sten!\nAnge utgangshastighet(m/s): ");
	scanf("%lf",&v);
	printf("Ange kastvinkel i forsta kvadranten (grader 0'-90'): ");
	do {
		scanf("%lf",&a);
		if(a < 0 || a > 90)
			printf("Mata in en vinkel mellan 0'- 90': ");
	}while (a < 0 || a > 90);
	a_rad=a*(PI/180);
	
	printf("i grader: %lf \ni radianer: %lf\n\n",a,a_rad);
	
	double h,d;
	
	h = (pow(v,2)*pow(sin(a_rad),2))/(2*G);
	d = (pow(v,2)*sin(2*a_rad))/G;
	
	printf("Med din indata landar stenen %.4lf meter bort fran dig!\nStenen nar en hojd pa %.4lf meter over utgangspunkten!\n\n",d,h);
	
	system("pause");
	return 0;
}
