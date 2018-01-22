/*
 *  File    : pss.c 
 *  Program : Paper, stone, scissor  game
 *  Author  : ...
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

#define MAX_TURNS 10

#define MAX_BUFFER 6		/* Tricky 5 won't do */

#define DRAW 0
#define COMPUTER_WIN 1
#define HUMAN_WIN 2

#define ROCK 0
#define SCISSOR 1
#define PAPER 2

#define STONE_STR "sten"	/* Used in logic not IO */
#define SCISSOR_STR "sax"
#define PAPER_STR "påse"





/* ------------------- Utilities ---------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/

int main()
{
  int human,
    computer,
    result,
    statistic;
  int i;
           
  srand( time(0) );
  statistic = 0;

  printf("Välkommen till sax, påse och sten ...\n"); 

 
  /*  Get human choice */

  /*  Get computer choice */
  /*  Print computer choice */
    
  /*  Get result depending on choices */
  /*  Print result */

  /*  Update statistics */

  
 
  /* Print total depending on statistics */
 
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

