/* --------------------------------------------------------
Fil : Labbuppgift
Program: Hangman
Utvecklare : Victor Sandin
Datum : 2017-05-17 / Version 1.0
  KÖRKOD: 5016eb
-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX_WORD_LEN 20
const int MAX_GUESS = 6;
const char ABORT_CH = '0';
const char filnamn [12] = "hangman.txt";
const int LOOSE = 0;
const int WIN = 1;
const int ABORTED = 2;
/* -------------- Funktionsdeklarationer -----------------*/
/* IO */
int get_user_input();
int read_guess(char word [MAX_WORD_LEN], char *mask, int len);
void right_guess (char guess, int number, char *mask);
void print_hangman(int guesses);
int check_result(char word [MAX_WORD_LEN], char *mask, int len);
/* Logic */
void maska_ord(char *mask, int antal);
/* File IO */
char *get_word();
/* Utilities */
void clear_stdin();
/************************************************************
 *                       MAIN
 ************************************************************/
 // å = \x86, ä = \x84, ö = \x94
int main()
{    
  char *word;	/* Word to guess (from file) */
  char mask [MAX_WORD_LEN];	/* Masked word (shown on screen (line 58) ) */
  int ch = 2;			/* User selection */
  int count;			/* Number of guesses */
  int result;			/* Winner */
  int len;
  int right_or_wrong = 0;
  char gubbe[6][21] = 	{
							{' ',' ',' ','/','/'},
							{' ',' ',' ','/','/','\\','\\',' '},
							{'K','L','A','R','T'}
						};
  /*   -------------------- Programstart  -----------------*/
  srand(time(0));
  do {
    printf("\nV\x84lkommen till HANG MAN 2017 by Victor Sandin\n");
    printf("Du har %d gissningar p\x86 dig (avsluta med 0)\n", MAX_GUESS );
    count = 0;
    word = get_word();                              //Hämtar slumpat or från fil   
    len = strlen(word) - 1;                         //Skriver ut längd på fil
    maska_ord(mask, len);
    printf( "\nDatorn har nu valt ett ord p\x86 %d bokst\x84ver\n", len );
	printf("F\x94r debug: %s", word);   
    /* ** GAME MAIN LOOP ** */
    while( true ){
        right_or_wrong = read_guess(word, mask, len);
        if (right_or_wrong == 2) {
            result = ABORTED;
            printf("Avbrutet\n");
            return 0;
        }
        if(right_or_wrong == 0) {
            count++;
        }
        print_hangman(count);
        printf("\n%s", mask);
        result = check_result(word, mask, len);
        if(result == 1) {
            break;
        }
        if (count == 6) {
            result = 0;
            break; 
        }   
    }
    /* ** RESULT ** */
    if( result == WIN ){
        printf("\n\nGrattis du vann!\n");
    }else if( result == LOOSE ){
        printf("\n\nTyvarr du f\x94rlorade ordet var: %s\n", word);
    }
    do {
    ch = get_user_input();   
    }while(ch == ABORTED);
  } while(ch == 0);
  return 0;
}
/***********************************************************
 *  ---------        Funktionsdefinitioner ----------------
 ***********************************************************/
/* -- Clear stdin -- */
void clear_stdin(){
	while( getchar() != '\n' );
}
/* -- Spela igen? -- */
int get_user_input(){
	char tkn = '0';
    int val = 1;
    printf("\nVill du spelas igen (j/n)?: ");
    scanf("%c", &tkn);
    if (tkn == 'n') {
        val = 1;
    }
     else if (tkn == 'j') {
        val = 0;
    } else val = 2;
    return val;
}
/* -- läs gissning -- */
int read_guess(char word[MAX_WORD_LEN], char *mask, int len) {
    char guess;
    int value = 0;
	fflush(stdin);
    printf("\nGissa Bokstav: ");
    scanf("%c", &guess);
    if(guess == ABORT_CH) {
        value = ABORTED;
        return value;
    }
    for(int i = 0; i < len; i++) {
        if(guess == word[i]) {
            right_guess(guess, i, mask);
            value = 1;
        }
    }
    clear_stdin();
    return value;
}
/* -- Hämta ord -- */
char *get_word() {
    srand(time(0));
    FILE *fd;
    int antal_ord;
    int slumptal;
    int counter = 0;
    fd = fopen("hangman.txt", "r");
    char *line = (char*)malloc(MAX_WORD_LEN * sizeof(char));
    fscanf(fd, "%i", &antal_ord);
    slumptal = rand()%antal_ord + 1;
    while(fgets(line, MAX_WORD_LEN, fd) != NULL) {
        if(counter == slumptal) {
            break;
        }
        else{
            counter++;
        }
    }
    return line;
}
/* -- MASKA ORD -- */
void maska_ord(char *mask, int antal) {
    int i;
    for(i = 0; i < antal; i++) {
        mask[i] = '_';
    }
    mask [i] = '\0';
}
/* -- Maska av bokstäver -- */
void right_guess (char guess, int number, char *mask) {
    mask[number] = guess;
}
/* -- Kontrollera om alla bokstäver är gissade -- */
int check_result(char word [MAX_WORD_LEN], char *mask, int len) {
    int comp = 0; 
    int result = 0;
    for (int i = 0; i < len; i++) {
        if(word[i] == mask[i]) {
            comp++;
        }
    }
    if(comp == len) {
        result = 1;
    }
    return result;
}
/* -- Skriver ut hangman -- */
void print_hangman(int guesses) {
    switch(guesses) {
        case 1:
            printf("         ---        \n");
            break;
        case 2:
            printf("         ---        \n");
            printf("          |         \n");
            break;
        case 3:
            printf("         ---        \n");
            printf("          |         \n");
            printf("          O         \n");
            break;
        case 4:
            printf("         ---        \n");
            printf("          |         \n");
            printf("          O         \n");
            printf("        //|\\\\       \n");
            break;
        case 5:
            printf("         ---        \n");
            printf("          |         \n");
            printf("          O         \n");
            printf("        //|\\\\       \n");
            printf("          |         \n");
            break;
        case 6:
            printf("         ---        \n");
            printf("          |         \n");
            printf("          O         \n");
            printf("        //|\\\\       \n");
            printf("          |         \n");
            printf("        // \\\\       \n");
            break;
    }
	
}
	//gubbe[5] = "   // \\   ";
	//gubbe[5] = {'.','.','.','/','/'};    // \\   ";
	
	//for(int i;)


//"   // \\   "