/*
 *  File    : change_calc.c 
 *  Program : Calculates change and denominations
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int valorAntal(int* vaxel, int* antal, int j);  //funktionsdeklaration

int main()
{
	int pris,bet,vaxel;
	//valörer 1000 500 200 100 50 20 10 5 2 1 
	int valor[10] = {0,0,0,0,0,0,0,0,0,0};
	int antal[10] = {1000,500,200,100,50,20,10,5,2,1};
	printf("Valor och vaxelraknare!\n\nAnge Pris(kr):\n");
	scanf("%i",&pris);
	printf("Ange betalt belopp(kr):\n");
	scanf("%i",&bet);
	
	vaxel = bet - pris;
	if(vaxel < 0){
		printf("Du har gett butiken for lite pengar och blev utsparkad med huvudet fore!!\n\n");
		system("pause");
		return 0;
	}
	int skugg_vaxel = vaxel;
	while(vaxel!=0){
		for(int j=0; j<10; j++){
			valor[j] = valorAntal( &vaxel, antal, j );
			if(vaxel==0) break;
		}
	}
	/*Första versionen, upprepande kod..
	
		while((vaxel/1000) > 0){
			valor[0]++;
			vaxel -= 1000;
		}
		while((vaxel/500) > 0){
			valor[1]++;
			vaxel -= 500;
		}
		while((vaxel/200) > 0){
			valor[2]++;
			vaxel -=200;
		}
		while((vaxel/100) > 0){
			valor[3]++;
			vaxel -= 100;
		}
		while((vaxel/50) > 0){
			valor[4]++;
			vaxel -= 50;
		}
		while((vaxel/20) > 0){
			valor[5]++;
			vaxel -= 20;
		}
		while((vaxel/10) > 0){
			valor[6]++;
			vaxel -= 10;
		}
		while((vaxel/5) > 0){
			valor[7]++;
			vaxel -= 5;
		}
		while((vaxel/2) > 0){
			valor[8]++;
			vaxel -= 2;
		}
		while((vaxel/1) > 0){
			valor[9]++;
			vaxel -= 1;
		}
	}*/
	printf("Du ska fa tillbaka %i kr i vaxel.\n",skugg_vaxel);
	printf("Du far:\n%i 1000-lapp(ar) \n%i 500-lapp(ar) \n%i 200-lapp(ar) \n%i 100-lapp(ar) \n%i 50-lapp(ar) \n%i 20-lapp(ar) \n%i 10-krona(or) \n%i 5-krona(or) \n%i 2-krona(or) \n%i 1-krona(or) \n\n"
		,valor[0],valor[1],valor[2],valor[3],valor[4],valor[5],valor[6],valor[7],valor[8],valor[9]);
		
		
	system("pause");
	return 0;
}
//funktioner
int valorAntal(int* vaxel, int* antal, int j){
	int i = 0;
	while((*vaxel / antal[j]) > 0){
		i++;
		*vaxel -= antal[j];
		
	}
	return i;
}