#include <stdio.h>

#define MAX 100

void LeeVector(int v[],int n){
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&v[i]);

}


void EliminaElemento(int v[], int *n, int pos){
	if(pos+1 < *n){
		int i;

		for(i=pos;i<*n;i++){
			v[i] = v[i+1];
		}

		*n = *n - 1;

	} else if((pos+1)==*n){
		*n = *n -1;
	}
}

void IntercambiaInt(int *a, int *b){
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}


void OrdenaSeleccion(int v[], int n){
	int i, j;
	int min;

	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(v[j] < v[min])
				min = j;
		}

		IntercambiaInt(&v[i],&v[min]);
	}
}

void EliminaRepetidosYObtenFrecuencias(int v[], int *n, int freq[], int *util_freq){
	int i, j, n_elem;

	i=0;
	OrdenaSeleccion(v,*n);

	while(i<*n-1){
		j = i;
		n_elem = 1;
		while(v[j]==v[j+1]){
			EliminaElemento(v,n,j);
			n_elem++;
		}
		
		freq[i] = n_elem; 
		i++;
	}

	*util_freq = *n;
}

void ImprimeVector(const int v[], int n){
	int i;

	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
} 

int main(){
	int elementos;
	int v[MAX];
	int frecuencias[MAX];
	int util_frecuencias;

	scanf("%d",&elementos);
	LeeVector(v,elementos);

	EliminaRepetidosYObtenFrecuencias(v,&elementos,frecuencias,&util_frecuencias);
	
	ImprimeVector(v,elementos);
	ImprimeVector(frecuencias,util_frecuencias);
	

	return 0;
}


	
	
	

		
