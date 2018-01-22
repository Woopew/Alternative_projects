/*
 *  File    : dist_gas.c 
 *  Program : Milage- and gasconsumtion- calculator
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int forraMil=0,nuMil=0, stracka=0;
	double bensin=0, forbrukning=0;
	
	printf("Hur långt har du kört?\nMata in din mätarställning (mil) fran ett ar sen:\n");
	scanf("%i",&forraMil);
	printf("Mata in din nuvarande matarstallning (mil):\n");
	scanf("%i",&nuMil);
	printf("Hur mycket bensin har du forbrukat under aret (liter):\n");
	scanf("%lf",&bensin);
	
	stracka = nuMil-forraMil;
	forbrukning = bensin/stracka;
	
	printf("Du har kort din bil ca %i mil och har en genomsnittsforbrukning pa %lf (liter/mil)\n",stracka,forbrukning);
	system("pause");
	return 0;
}
