#include <stdio.h>
#define MAX 100

void Intercambia(int *a, int *b){		/// Función auxiliar que intercambia el valor de dos elementos
	int aux = *a;
	*a = *b;
	*b = aux;
}

int PosicionMayorEntre(const int v[], int util, int derecha){		/// Devuelve la posición del elemento mayor entre dos posiciones distintas cualesquiera 
	int posicion = derecha;
	int i;
	int maximo = v[derecha];

	for(i=derecha;i<util;i++){
		if(maximo < v[i]){
			maximo = v[i];
			posicion = i;
		}
	}
	
	return posicion;
}
			


void OrdenaDescendente(int v[], int util){		/// Recorre el vector, intercambiando en cada iteración el elemento mayor con el elemento i-ésimo 
	int i;
	int indice_a_intercambiar;

	for(i=0;i<util;i++){
		indice_a_intercambiar = PosicionMayorEntre(v,util,i);
		Intercambia(&v[i],&v[indice_a_intercambiar]);
	}
}

void ImprimeArray(const int v[], int util){
	int i;
	for(i=0;i<util;i++)
		printf("%d \n",v[i]);
}


int main(){
	int v[MAX] = {34,-2,45,67,0,1,2,3,345,23,1,9};
	int util = 10;
	int i;


	OrdenaDescendente(v,util);

	ImprimeArray(v,util);

	return 0;
}

	
