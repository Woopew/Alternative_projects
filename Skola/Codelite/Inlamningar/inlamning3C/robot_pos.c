/*
 *  File    : robot_pos.c 
 *  Program : Move and turn in grid - Robot
 *  Author  : Victor Sandin
 * Körkod: b5d234
 */
#include <stdio.h>
#include <stdlib.h>


struct robot{
	int x;
	int y;
	char rikt;
};

void moveRobot(int *x, int *y, char rikt);
void turnRobot(char *rikt);


int main()
{
	struct robot roboten;
	roboten.x = 0;
	roboten.y = 0;
	roboten.rikt = 'u';
	
	char ans[20];
	char action;
	int i=0;
	
	printf("Mata in robotens startposition, forst 'x' sen 'y': \n");
	scanf("%i",&roboten.x); fflush(stdin);
	scanf("%i",&roboten.y); fflush(stdin);
	printf("Robotens position: [%i, %i] (x,y)\n",roboten.x, roboten.y);
	printf("Roboten pekar just nu: %c (u=upp, n=ner, h= hoger, v=vanster)\n", roboten.rikt);
	printf("Vill du vrida roboten medurs eller flytta roboten tryck: t (turn) eller m (move)\n");
	
	while(1){
		scanf("%s", ans); fflush(stdin);
		
		for(i=0;i<20;i++){
			action = ans[i];
			if(ans[i] == '\0')break;
			if(action == 't'){
				turnRobot(&roboten.rikt);
			}
			if(action == 'm'){
				moveRobot(&roboten.x, &roboten.y, roboten.rikt);
			}
		}	
		printf("Ny pos: [%i,%i]\nRiktning: %c \n", roboten.x, roboten.y,roboten.rikt);
		printf("Mata in ny startposition, forst 'x' sen 'y': \n");
		scanf("%i",&roboten.x); fflush(stdin);
		scanf("%i",&roboten.y); fflush(stdin);
		printf("Vill du vrida roboten medurs eller flytta roboten tryck: t (turn) eller m (move)\n");
	}
	

	system("pause");
	return 0;
}

void moveRobot(int *x, int *y, char rikt){
	switch(rikt){
		case 'u': *y=*y+1;
		break;
		case 'n': *y=*y-1;
		break;
		case 'h': *x=*x+1;
		break;
		case 'v': *x=*x-1;
		break;
	}
}
void turnRobot(char *rikt){
		if(*rikt == 'u') *rikt = 'h'; 
	else if(*rikt == 'n') *rikt = 'v';
	else if(*rikt == 'h') *rikt = 'n';
	else if(*rikt == 'v') *rikt = 'u';
}
