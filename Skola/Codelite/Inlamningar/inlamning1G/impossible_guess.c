/*
 *  File    : impossible_guess.c 
 *  Program : Guess 0-100 to win, random luck game.
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	
	srand(time(0));
	int gissning =1, tal=-1, i=0;
	
	while(gissning!=tal && gissning > 0){
		tal = rand()%100 + 1;
		printf("Gissa på ett tal mellan 1-100! (Avsluta genom att skriva ett negativt tal)\n");
		scanf("%i",&gissning);
		if(gissning == tal){
			printf("Grattis du gissade ratt!\n\n");
			//break;
		}
		else if(gissning != tal && gissning > 0){
			printf("Du ar samst pa att gissa! Fel!\n\n");
			//break;
		}
		i++;
		if(i>9)break;
	}
	printf("Nu avslutas programmet!\nDu spelade %i ganger!\n\n",i);
	
	
	system("PAUSE");
	return 0;
}
