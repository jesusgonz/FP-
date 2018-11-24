#include <stdio.h>

#define MAX 100 

///****************************************************************************///
/// Precondición: que los dos vectores tengan el mismo número de elementos ////
/// Algoritmo: se declara una variable booleana son_iguales inicializada a true, se recorre el vector mientras son_iguales se cumpla, para ello en cada iteración se realiza una comparación entre los dos elementos i-ésimos del vector ///
/// Devuelve la variable booleana son_iguales ///
///*******************************************************************************///

int IgualesP(const char c1[], const char c2[], int util){		/// Precondición: que los dos vectores tengan la misma longitud(=util)
	int son_iguales = 1;
	int i = 0;

	for(i;i<util && son_iguales; i++){
		if(c1[i] != c2[i])
			son_iguales = 0;
	}

	return son_iguales;
}
		

int main(){
	char c1[MAX];
	char c2[MAX];
	int util = 10;
	int i = 0;
	int son_iguales;

	for(i;i<util;i++){
		scanf("%c", &c1[i]);
		c2[i] = c1[i];
	}

	son_iguales = IgualesP(c1,c2,util);

	if(son_iguales)
		printf("Son iguales");
	else
		printf("No son iguales");

	return 0;
}



		
