#include <stdio.h>

#define MAX 100 

void LeeVector(int v[],int n){
	int i;

	for(i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
}


void Intercambia(int *a, int *b){
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void SelectionSort(int v[],int n){
	int i,j;
	int min;

	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(v[j] < v[min])
				min = j;
		}

		Intercambia(&v[i],&v[min]);
	}
}

void InsertaPos(int v[],int elem, int *util, int pos){
	int i;
	for(i=*util;i>pos;i--){
		v[i] = v[i-1];
	}

	v[pos] = elem;
	*util = *util + 1;
}

void InsertaOrdenado(int v[],int valor, int *util){
	int i;

	for(i=*util; i > 0 && valor < v[i-1];i--){
		v[i] = v[i-1];
	}

	v[i] = valor;
	*util = *util + 1;
}

void InsertionSort(int v[],int n){
	int izda = 1;

	while(izda < n){
		InsertaOrdenado(v,v[izda],&izda);
	}
}

void BubbleSort(int v[],int n){
	int i = 1;
	int cambio = 1;

	while(cambio){
		cambio = 0;
		i = 0;
		while(i<n-1){
			if(v[i]>v[i+1]){
				Intercambia(&v[i],&v[i+1]);
				cambio = 1;
			}
			i++;
		}
	}
}

void ImprimeVector(int v[], int n){
	int i;

	for(i=0;i<n;i++){
		printf("%d ",v[i]);
	}
}

int main(void){
	int v[MAX] = {-34,456,78,98,97,3,5,6,100};
	int util = 9;

	BubbleSort(v,util);
	ImprimeVector(v,util);

	return 0;
}

		
			
