/*
 *  File    : run_calc.c 
 *  Program : calculates total time from race
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//int forsta[3], andra[3], result[3];
	int tt_1,mm_1,ss_1,
		tt_2,mm_2,ss_2,
		tt_r,mm_r,ss_r;
	
	printf("Lopartestet!\n\n");
	printf("Hur manga timmar tog forsta loppet?\n");
	scanf("%i",&tt_1);
	printf("Hur manga minuter tog forsta loppet?\n");
	scanf("%i",&mm_1);
	printf("Hur manga sekunder tog forsta loppet?\n");
	scanf("%i",&ss_1);
	printf("Forsta loppet tog %02i:%02i:%02i\n\n",tt_1,mm_1,ss_1);
	
	printf("Hur manga timmar tog andra loppet?\n");
	scanf("%i",&tt_2);
	printf("Hur manga minuter tog andra loppet?\n");
	scanf("%i",&mm_2);
	printf("Hur manga sekunder tog andra loppet?\n");
	scanf("%i",&ss_2);
	
	printf("Andra loppet tog %02i:%02i:%02i\n\n",tt_2,mm_2,ss_2);
	
	tt_r = tt_1+tt_2;
	mm_r = mm_1+mm_2;
	ss_r = ss_1+ss_2;
	
	if(ss_r>59){ 
		mm_r++;
		ss_r -= 60;
	}
	if(mm_r>59){ 
		tt_r++;
		mm_r-=60;
	}
	
	printf("Den sammanlagda tiden for bada loppen blir %02i:%02i:%02i \n\n",tt_r,mm_r,ss_r);
	
	
	system("pause");
	return 0;
}
