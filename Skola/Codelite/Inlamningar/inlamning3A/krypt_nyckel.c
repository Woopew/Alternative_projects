/*
 *  File    : krypt_nyckel.c 
 *  Program : Avkryptering från fil
 *  Author  : Victor Sandin
 * Körkod:INTE KLAR
 */
#include <stdio.h>
#include <stdlib.h>
 


void read_file(char bok[],FILE* fp);
void get_string(char inm[]);

int main()
{
	
	
	char text[200],inm[10];
	printf("Valkommen till krypt special!\n\n");
	
	// FILE * fopen(const char *filename, const char *mode)
	FILE *fp = fopen("hemlig.txt", "r");
	if (fp == NULL) {
		puts("Filen fanns ej.");
	}
	else {
		puts("Det gick bra att  ö \x94ppna den filen.");
	}

	get_string(inm);
	printf("%s\n\n",inm);
	//read_file(text,fp);
	fgets(text,200,fp);
	
	/*
		for(int u=0;u < 200 ;u++){
		printf("%c",text[u]);
		if(text[u] == '\0') break;
	}*/
	
	for(int i = 0;i<200;i++){
		if(text[i]=='\0') break;
		printf("%c",text[i]);
		
	}
	system("pause");
return 0;

}

void read_file(char bok[], FILE *fp){
	int i;
	char tecken; 
	for(i=0;i<200;i++){
		tecken = fgetc(fp);
		bok[i] = tecken; 
		if(tecken == EOF) break;
	}
	
}
void get_string(char inm[]){
	scanf("%9s",inm);
}