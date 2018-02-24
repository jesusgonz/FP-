#include <stdio.h>
#include <math.h>

#define MAX 20

void LeeEnteros(int v[], int n){
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
}

void ImprimeVector(const int v[], int n){
	int i;
	
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
}

/*************************************/
/*Se asume que el vector tiene 20 posiciones ocupadas */
/*************************************/


double ConvierteAReal(const int v[], int posDec, int n){
	int i;
	double num = 0.0;

	for(i=0;i<n;i++){
		num += v[i]*pow(10.0,posDec-1-i);
		
	}

	return num;
}

int main(){
	double num_v1, num_v2, multiplicacion;
	int posDec_1, posDec_2;
	int v1[MAX];
	int v2[MAX];

	LeeEnteros(v1,MAX);
	scanf("%d",&posDec_1);
	LeeEnteros(v2,MAX);
	scanf("%d",&posDec_2);

	num_v1 = ConvierteAReal(v1,posDec_1,MAX);
	num_v2 = ConvierteAReal(v2,posDec_2,MAX);

	
	multiplicacion = num_v1*num_v2;

	printf("\n%f",multiplicacion);

	return 0;
}






