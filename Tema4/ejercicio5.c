#include <stdio.h>

#define MAX 100		/// Número de elementos máximo del vector

///****************************************************************************///
/// Param: array de entero que se va a analizar, posición del elemento a analizar y número de elementos útiles del array ///
/// Algoritmo: se declara una variable booleana y se recorre el vector hasta posición mientras la variable booleana sea falsa, posteriormente si la variable booleana es falsa se devuelve 0, en caso contrario se recorre el array desde posición hasta util-1 comparando si el elemento está repetido, en caso de que no esté repetido devuelve un 1(true)///
///****************************************************************************///

int RepetidoP(const int v[], int posicion, int util){
	int repetido = 0;
	int i;

	for(i=0;i<posicion && !repetido;i++){
		if(v[i]==v[posicion])
			repetido = 1;
	}

	for(i=posicion;i<util && !repetido;i++){
		if(v[i]==v[posicion])
			repetido = 1;
	}

	return repetido;
}



