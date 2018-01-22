/*
 *  File    : crypt_13.c 
 *  Program : Encrypts your letter string-input 
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ord[21],krypt[21];
	int i,k,j,a,c=0,godis;
	
	printf("Kryptering special!\n");
	
	while(1){
		int b=0;
		printf("Skriv in ditt ord (max 20 bokstaver) Avsluta med EOF(ctrl+z): ");
		a = scanf("%20s",ord);
		if(a==EOF)break;						//Avsluta program vid EOF (ctrl+z) inmatning 
		for(i=0; ord[i] != '\0';i++);			//bestäm antal inmatade bokstäver i ord-array
		for(godis=0;godis<i;godis++){
			if((ord[godis] < 65 || ord[godis] > 90) && (ord[godis] < 97 || ord[godis] > 122)){ 				//bara stora och små bokstäver tillåts, inga andra tecken
				b=1;
				break;
			}
		}
		if(b==1){
			printf("-----------------------------Endast bokstaver tillatet!-----------------------------\n");
		}
		while(b!=1){
			for(j=0;j<=i;j++){
				c = ord[j];
				//if(ord[j]=='0')break;
				if((c<91 && c>77) || (c<123 && c>109)){
					c -= 13;
					krypt[j] = c;
				}
				else {
					c+=13;
					krypt[j] = c;
				}
			}
			for(k=0;k<i;k++){
				printf("%c",krypt[k]);
				if(k == (i-1)){
					printf("\n");
				}
			}
			if(b!=1)break;
		}
	}
	//system("pause");
	return 0;
}
