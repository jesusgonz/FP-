#include <stdio.h>

#define MAX 100

///***********************************************************************************************///
///Algoritmo: en cada iteración intercambia la posición i con util-i. Se puede implementar con una función auxiliar de intercambiar
///***********************************************************************************************///

void InvertirVector(char v[], int util){	
	char aux;
	int izda = util -1;
	int dcha; 

	for(dcha=0;dcha<(util-1)/2;dcha++){
		aux = v[izda];
		v[izda] = v[dcha];
		v[dcha] = aux;
		izda--;
	}
}

///****************************************************************************************************///
/// Función auxiliar que imprime un vector de caracteres de longitud n ///
///*****************************************************************************************************///

void ImprimirVector(const char v[], int n){
	int i = 0;
	for(i;i<n;i++)
		printf("%c \n",v[i]);
}

int main(){
	char v[MAX];
	int util = 10;
	int i;

	for(i=0;i<util;i++)				//// Lectura de valores que se almacenan en el vector 
		scanf("%c",&v[i]);

	InvertirVector(v,util);
	ImprimirVector(v,util);

	return 0;
}


		
