/*
 *  File    : auto_rain.c 
 *  Program : Displays random rain over 20 years in row diagram (histogram)
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	while(1){
		srand(time(0));
		int nederbord[20],ned_100=0, k, ar[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		for(int i=0;i<20;i++){
			nederbord[i]=rand()%3001;
			//for(int l;l<1000;l++);
		}
		printf("Ar   0         1         2         3   x1000(mm)\n");
		for(int j=0;j<20;j++){
			printf("%2i   |",ar[j]);
			ned_100 = nederbord[j]/100;
			for(k = 0;k<ned_100;k++){
				printf("*");
			}
			printf("\n");
		}
		system("pause");
	}
	return 0;
}
