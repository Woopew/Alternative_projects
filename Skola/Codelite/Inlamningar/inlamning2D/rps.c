/*
 *  File    : rps.c 
 *  Program : Rock, paper, scissor - game
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

#define MAX_TURNS 5

#define MAX_BUFFER 6		/* Tricky 5 won't do */

#define DRAW 0
#define COMPUTER_WIN 1
#define HUMAN_WIN 2

#define ROCK 0
#define SCISSOR 1
#define PAPER 2

#define ROCK_STR "sten"	/* Used in logic not IO */
#define SCISSOR_STR "sax"
#define PAPER_STR "pase"

/* ------------------- Utilities ---------------*/
void clear_stdin();
int human_choice();
int computer_choice();
void print_computer_choice(int val);
int get_result(int human, int computer);
void print_result(int result);
void up_stat(int result, int *statistic_h, int *statistic_c);
void print_stat(int statistic_h, int statistic_c);
int play_again();
/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main(){
	int human,
	computer,
	result,
	statistic_h=0,statistic_c=0;
	int i,again=1;
			   
	srand( time(0) );

	printf("Valkommen till sten, sax och pase\n"); 

	while(again){
		for(i=0;i<MAX_TURNS;i++){
		/*  Get human choice */
		human = human_choice();
		/*  Get computer choice */
		computer = computer_choice();
		/*  Print computer choice */
		print_computer_choice(computer);
		/*  Get result depending on choices */
		result = get_result(human, computer);
		/*  Print result */
		print_result(result);
		/*  Update statistics */
		up_stat(result, &statistic_h, &statistic_c);
		
		/* Print total depending on statistics */
		print_stat(statistic_h,statistic_c);
		}
		/*Play one more round y/n*/
		again = play_again();
		
	}
	printf("\n---------------------Avslutar---------------------\n\n");
	for(int p=0;p<10000;p++){
		for(int y=0;y<25000;y++);
	}
	  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/

void clear_stdin()
{
	while( getchar() != '\n' ){;}
}

int human_choice(){
	char val[5];
	int vapen=-1,om=1;
	do{
		printf("Valj ditt vapen (sten,sax,pase): "); scanf("%s",val);
		clear_stdin();
		if((val[0] == 's' && val[1] == 't' && val[2] == 'e' && val[3] == 'n') || (val[0] == 'S' && val[1] == 'T' && val[2] == 'E' && val[3] == 'N')){ 
			vapen = ROCK;
			om = 0;
		}
		else if((val[0] == 's' && val[1] == 'a' && val[2] == 'x') || (val[0] == 'S' && val[1] == 'A' && val[2] == 'X' && val[3] == 'N')){
			vapen = SCISSOR;
			om = 0;
		}
		else if((val[0] == 'p' && val[1] == 'a' && val[2] == 's' && val[3] == 'e') || (val[0] == 'P' && val[1] == 'A' && val[2] == 'S' && val[3] == 'E')){
			vapen = PAPER;
			om = 0;
		}
		else{
			printf("sa svart ar det inte att stava ratt?\n");
		}
	}while(om);
	return vapen;
}

int computer_choice(){
	int val = rand()%3;
	int vapen=-1;
	switch (val){
		case 0: 
			vapen = ROCK;
			break;
		case 1: 
			vapen = SCISSOR;
			break;
		case 2: 
			vapen = PAPER;
			break;
	}
	return vapen;
}

void print_computer_choice(int val){
	switch(val){
		case 0:
			printf("Datorn valde sten\n");
			break;
		case 1:
			printf("Datorn valde sax\n");
			break;
		case 2:
			printf("Datorn valde: pase\n");
			break;
	}
}

int get_result(int human,int computer){
	int resultat=-1, 
	result_matrix[3][3]={ {0,1,2},
						  {2,0,1},
						  {1,2,0} };
	resultat = result_matrix[human][computer];
	return resultat;
}

void print_result(int result){
	switch(result){
		case 0:
			printf("Oavgjort!\n");
			break;
		case 1:
			printf("Du vann!\n");
			break;
		case 2:
			printf("Datorn vann!\n");
			break;
	}
	
}

void up_stat(int result, int *statistic_h, int *statistic_c){
	switch(result){
		case 0: break;
		case 1:
			*statistic_h = *statistic_h + 1;
			//printf("statistic_h = %i\n",*statistic_h);
			break;
		case 2:
			*statistic_c = *statistic_c + 1;
			//printf("statistic_c = %i\n",*statistic_c);
			break;
	}
	return;
}

void print_stat(int statistic_h, int statistic_c){
	if(statistic_c < statistic_h){
		printf("Du leder med %i over datorns %i vinster\n",statistic_h,statistic_c);
	}
	else if(statistic_c > statistic_h){
		printf("Datorn leder med %i over dina %i vinster\n",statistic_c,statistic_h);
	}
	else if(statistic_c == statistic_h){
		printf("Ni har lika manga vinster: %i\n",statistic_c);
	}
	return;
}
int play_again(){
	char spela;
	printf("Vill du spela igen?(j/n): ");
	scanf("%c", &spela);
	while(1){
		if(spela == 'j' || spela =='J'){
			clear_stdin();
			return 1;
		}
		else if(spela == 'n' || spela == 'N'){
			clear_stdin();
			return 0;
		}
		else{
			printf("Du maste valja mellan 'j' eller 'n'!\n");
			printf("Vill du spela igen?(j/n): ");
			clear_stdin();
			scanf("%c", &spela);
		}
	}
}