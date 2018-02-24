#include <stdio.h>

#define MAX 100

void LeeVector(int v[], int n){
	int i;

	for(i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
}

void ImprimeVector(const int v[],int n){
	int i;

	for(i=0;i<n;i++){
		printf("%d ",v[i]);
	}

	printf("\n");
}



void IntercambiaInt(int *a, int *b){
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void OrdenaSeleccion(int v[], int n){
	int i,j,min;

	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(v[j] < v[min]){
				min = j;
			}
		}

		IntercambiaInt(&v[i],&v[min]);
	}
}

float Mediana(const int v[], int n){
	OrdenaSeleccion(v,n);

	if(n%2==0)
		return (v[n/2]+(v[n/2 -1]))/2.0;
	else
		return v[n/2];
}


int main(){
	int v[MAX];
	int n;
	float mediana;

	scanf("%d",&n);
	LeeVector(v,n);

	mediana = Mediana(v,n);

	printf("%f",mediana);

	return 0;
}
