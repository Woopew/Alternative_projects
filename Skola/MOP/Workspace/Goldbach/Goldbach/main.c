#include <stdio.h>
#include <stdlib.h>
#include "is_prime.h"

int main(int argc, char **argv)
{
	int tal = 0;
	int *pnt_tal;
	pnt_tal = &tal;
	int return_value;
	return_value = 0;
	
	while(1){
	
	
		printf("Skriv ett tal som ar storre an 2:\n");
		scanf("%i",pnt_tal);
	
		if(tal <= 1){
			return 0;
		}
		
		return_value = is_prime(pnt_tal);
		
		if(return_value == 1)
			printf("Talet ar ett primtal!\n");
		else
			printf("Talet ar inte ett primtal\n");
		
	}
	
	system("pause");
	return 0;
}
