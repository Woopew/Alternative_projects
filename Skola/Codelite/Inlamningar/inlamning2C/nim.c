/*
 *  File    : nim.c 
 *  Program : Nim game
 *  Author  : Victor Sandin
 * Körkod: ...
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>     


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins,
	repris;			/* Number of coins taken */
  
  srand( time(0) );		/* Setup random */

  printf("Valkommen till NIM by Victor Sandin!");
 
	repris = 1;					//initierar repris så programmet körs första gången
	while(repris){				//Skapar en möjlighet att köra hela programmet en gång till, val sker i play_again()-funktion
		pile = MAX_COINS;		/* Set start values (= init) */
		player = HUMAN;
  /* 
   *  Program main loop 
   */
		while( true ) {
			printf("Det ligger %d  mynt i hogen\n", pile );
			
			if( player == HUMAN ){
				n_coins = human_choice(pile);      
			}
			else{
				n_coins = computer_choice(pile);
				printf("- Datorn tog %d\n", n_coins);      
			}
			pile -= n_coins;
			if(pile>1 || pile < 1){			//Byt spelare om om högen är mindre än 1 eller större än 1, förloraren är den som tar sista myntet. Kanske var buggen som var inlagd?
				player = toggle( player );
			}
			if( pile <= 1 ){
				break;
			}
		}
		write_winner( player );
		clear_stdin();
		repris = play_again();
	}
	printf("\n------------------------Avslutar------------------------\n");
	for(int p=0;p<10000;p++){
		for(int y=0;y<25000;y++);
	}
	//system("pause");
	return 0;
	/*
	* end main loop
	*/
	   
}
/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/
void clear_stdin(){
  while( getchar() != '\n' ){;}
}

int human_choice(int pile){
	int val=0;
	do{
	printf("Hur manga mynt vill du ta?(1-3): ");
	scanf("%i",&val);
	if(val > pile){
		printf("Det finns inte tillrackligt med mynt for det valet.");
		val=5;
	}
	
	}while(val > 3 || val < 1);
	return val;
}

int computer_choice(int pile){
	int val=20;
	if(pile < 5){					//Tillåt datorn lite AI om det är mellan 2-4 mynt kvar i högen
		switch (pile){
			case 4:
				val = 3;
				break;
			case 3:
				val = 2;
				break;
			case 2:
				val = 1;
				break;
		}
	}
	else{
		val = rand()%3+1;			//Mer än 4 mynt kvar, datorn väljer random mynt att ta mellan 1-3
	}
	
	return val;
}

void write_winner(int player ){
	if(player==1)
		printf("Datorn har besegrat dig!\n");
	else
		printf("Du vann utan problem!\n");
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

int toggle( int player ){
	if(player == 0) player = 1;
	else player = 0;
	return player;
}
