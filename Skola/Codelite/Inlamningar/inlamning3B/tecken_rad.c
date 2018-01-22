/*
 *  File    : tecken_rad.c 
 *  Program : Räknar rader och tecken i txt dokumentet "teckenorader.txt"
 *  Author  : Victor Sandin
 * Körkod: cf5913
 */

#include <stdio.h>
#include <stdlib.h>

//Funktionsdeklaration
void get_lines_kar(int* lines, int* kar, FILE *fp);
void quit();


int main(int argc, char **argv){
	
	int lines=1,kar=0;
	
	printf("V\x84lkommen!\n\n");
	
	//Försöker öppna dokument för läsning och ger resultat till skärm
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		puts("Filen fanns ej.");
		quit();
		return 0;
	}
	else {
		puts("Det gick bra att \x94ppna den filen.");
	}
	
	get_lines_kar(&lines, &kar, fp);
	//kar = kar - lines;
	printf("I ditt dokument har du %i rader och %i tecken.\n\n",lines,kar);
	
	quit();
	system("pause");
	return 0;
}

//hämtar ett tecken i taget tills eof möts, incrementerar lines vid '\n' och tecken vid resterande.
void get_lines_kar(int* lines, int* kar, FILE *fp){
	char karak;
	while(1){
		karak = fgetc(fp);
		if(karak == EOF){
			break;
		}
		if(karak != '\n'){
			*kar = *kar + 1;
		}
		if(karak == '\n'){
			*lines += 1;
		}
	}
}
void quit(){
	printf("-------------------------Avslutar-------------------------\n\n");
	//Avslutningsdelay
	for(int p=0;p<50000;p++){
		for(int y=0;y<30000;y++);
	}
}