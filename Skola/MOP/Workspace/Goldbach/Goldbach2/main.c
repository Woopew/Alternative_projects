#include <stdio.h>
#include <stdlib.h>
#include "is_prime.h"

int main(){

int tal = 0;
int *pnt_tal;
pnt_tal = &tal;


	while(1)
	{
		printf("Skriv ett tal, se om det ar jamt:\n");
		scanf("%i",pnt_tal);
		if(*pnt_tal <= 2)
				return 0;
		while(*pnt_tal < 4){
			printf("Talet ar for litet! forsok igen:\n");
			scanf("%i",pnt_tal);
		}
		if(*pnt_tal % 2 == 0){
			 printf("Talet ar jamt!");
			int n1 = 2;
			int n2 = *pnt_tal - n1;
			for(n1 = 2; n1 < *pnt_tal/2; n1++){
				for(n2 = *pnt_tal; n2 > (*pnt_tal/2); n2--)
				if(n2+n1==*pnt_tal){
					int k = is_prime(n1);
					int s = is_prime(n2);
					if(k+s == 2){
				printf("%i + %i = %i",n1,n2,*pnt_tal);
				}
				}
			}	
		}
		else 
			printf("Talet ar inte jamt forsok igen:\n");
	
	}
	return 0;
}