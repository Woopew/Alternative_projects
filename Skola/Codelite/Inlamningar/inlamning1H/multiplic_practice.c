/*
 *  File    : multiplic_practice.c 
 *  Program : Practice multiplication table
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(0));
	int a=0,b=0,svar=0,svarMitt=0, ratt=0, antal=0,tabell=0;
	printf("Valkommen till gangertabellen! (Avsluta med 0 eller negativt tal)\n\n");
	printf("Valj gangertabell(1-9) 0 ger random!\n");
	scanf("%i",&tabell);
	
	if(tabell == 0){
		do{
			a=rand()%9+1;
			b=rand()%9+1;
			svar = a * b;
			
			printf("%i * %i = ",a,b);
			scanf("%i",&svarMitt);
			
			if(svarMitt < 0)break;
			else if(svar==svarMitt){
				printf("Grattis du kan rakna!\n");
				ratt++;
				antal++;
			}
			else if(svar != svarMitt && svarMitt >= 0){
				printf("Fortsatt ova, ratt svar ar %i\n", svar);
				antal++;
			}
		}while(svarMitt >= 0);
	}
	else{
		do{
			a=tabell;
			b=rand()%9+1;
			svar = a * b;
			
			printf("%i * %i = ",a,b);
			scanf("%i",&svarMitt);
			
			if(svarMitt < 0)break;
			else if(svar==svarMitt){
				printf("Grattis du kan rakna!\n");
				ratt++;
				antal++;
			}
			else if(svar != svarMitt && svarMitt >= 0){
				printf("Fortsatt ova, ratt svar ar %i\n", svar);
				antal++;
			}
		}while(svarMitt >= 0);
	}
	printf("Du fick %i ratt av %i mojliga!\n",ratt,antal);
	system("pause");
	return 0;
}
