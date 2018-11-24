#include <stdio.h>
#define MAX 100

int ElementoMasGrande(const double v[], int util){     //// Devuelve la posición del elemento mayor en un array de util-elementos
	int maximo = v[0];
	int posicion = 0;
	int i;
	
	for(i=1;i<util;i++){
		if(maximo < v[i]){
			posicion = i;
			maximo = v[i];
		}
	}

	return posicion;
}


void EliminarElemento(double v[], int* util, int posicion){		/// Elimina un elemento del array desplazando todos los elementos a i-1, siendo i su posición original
	int i;

	for(i=posicion;i<(*util-1);i++)
		v[i]=v[i+1];

	*util--;							/// Actualiza el valor de elementos útiles
}

/******************************************************/
/// Algoritmo: Buscar el elemento más grande, devolverlo en una variable que se pasa por referencia, eliminarlo y posteriormente repetir la búsqueda y volver a devolverlo en otra variable que se pasa por referencia  /// (El vector original no se modifica, se realiza un paso por valor). Con este algoritmo es posible conseguir los n más grandes.
/******************************************************/

void PrimerYSegundoElementoMasGrande(const double v[], int util, double* primer, double* segundo){	    
	int posicion;																							
	posicion = ElementoMasGrande(v,util);
	*primer = v[posicion];
	EliminarElemento(v,&util,posicion);
	posicion = ElementoMasGrande(v,util);
	*segundo = v[posicion];
}

void NMasGrandes(const double v[], int util, double p[], int n){		//// p contiene los n valores más grandes 
	int posicion;
	for(i=0;i<n;i++){
		posicion=ElementoMasGrande(v,util);
		p[i]=v[posicion];
		EliminarElemento(v,&util,posicion);
	}
}

int main(){
	double v[MAX];
	double primer, segundo;
	int util = 10;
	int i;

	for(i=0;i<util;i++)
		scanf("%lf",&v[i]);

	PrimerYSegundoElementoMasGrande(v,util,&primer,&segundo);

	printf("%f %f",primer,segundo);

	return 0;
}

		


