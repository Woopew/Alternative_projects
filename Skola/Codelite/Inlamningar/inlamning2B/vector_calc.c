/*
 *  File    : vector_calc.c 
 *  Program : Normalize single vector, Dot-product of two vectors or cross-product of two vectors
 *  Author  : Victor Sandin
 * Körkod: ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void normalisera(float vector[]);
void normalisera_(float vector[], float normVector[]);
void getVector(float vector[]);
void kryss(float vector[],float vector2[],float kryssvector[]);
void skalar(float vector[],float vector2[],float* skalvector);


int main()
{
	float vector[3],vector2[3],normVector[3],kryssvector[3],skalvector=0;
	printf("Mata in din forsta vektor(x,y,z):\n");
	int val;
	for(int i=0;i<3;i++){
		scanf("%f",&vector[i]);
	}
	printf("Din vektor:                    %.3fx %.3fy %.3fz\n",vector[0],vector[1],vector[2]);
	printf("Vill ha 1:Normalvektor 2:Skalarprodukt 3:Kryssprodukt\n");
	scanf("%i", &val);
	
	
	if(val == 1){
	normalisera_(vector,normVector);
	printf("Din normaliserade vektor blir: %.3fx %.3fy %.3fz\n",normVector[0],normVector[1],normVector[2]);
	}
	else if(val == 2){
		getVector(vector2);
		skalar(vector,vector2,&skalvector);
		printf("Skalarprodukten av vektorer blir: %.3f\n",skalvector);
	}
	else if(val == 3){
		getVector(vector2);
		kryss(vector,vector2,kryssvector);
		printf("Kryssprodukten av vektorer blir: %.3fx %.3fy %.3fz\n",kryssvector[0],kryssvector[1],kryssvector[2]);
	}
	
	
	
	system("pause");
	return 0;
}
void normalisera_(float vector[], float normVector[]){
	float abs = sqrt(powf(vector[0],2)+powf(vector[1],2)+powf(vector[2],2));
	for(int i=0;i<3;i++){
		normVector[i] = vector[i]/abs;
	}
}
void normalisera(float vector[]){
	float abs = sqrt(powf(vector[0],2)+powf(vector[1],2)+powf(vector[2],2));
	for(int i=0;i<3;i++){
		vector[i] = vector[i]/abs;
	}
}

void skalar(float vector[],float vector2[],float* skalvector){
	
	*skalvector = vector[0] * vector2[0] + vector[1] * vector2[1] + vector[2] * vector2[2];
	
/*	*skalvector = vector[0] * vector2[0];
	*skalvector = *skalvector + (vector[1] * vector2[1]);
	*skalvector = *skalvector + (vector[2] * vector2[2]);*/
}

void kryss(float vector[],float vector2[],float kryssvector[]){
	kryssvector[0] = (vector[1]*vector2[2]) - (vector[2]*vector2[1]); 
	kryssvector[1] = (vector[2]*vector2[0]) - (vector[0]*vector2[2]);
	kryssvector[2] = (vector[0]*vector2[1]) - (vector[1]*vector2[0]);
	
}
void getVector(float vector[3]){
	printf("mata in din andra vektor(x,y,z):\n");
	for(int i=0;i<3;i++){
			scanf("%f",&vector[i]);
	}
}