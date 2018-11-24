#include <stdio.h>							/* Biblioteca de E/S */

#define MAX 1000							/* Constante de preprocesado */

struct Conjunto1000{							/* Declaración de la estructura */
	int num_elem;
	int elementos[MAX];
};

typedef struct Conjunto1000 Conjunto1000;				/* Declaración de Conjunto1000 como un tipo. */

int PerteneceP(int v[],int n,int elem){					/* Recorre el array, devolviendo true si el elemento está en él. */
	int pertenece = 0;
	int i;

	for(i=0;i<n && !pertenece;i++){
		if(v[i]==elem)
			pertenece = 1;
	}

	return pertenece;
}

void Intercambia(int *a, int *b){					/* Intercambia dos enteros, se podría implementar a nivel de conjunto pero proporciona menor abstracción. */
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void SelectionSort(int v[],int n){					/* Recorre el array, en la iteración i-ésima selecciona la posición del elemento mayor entre a[i],...,a[r] para intercambiarlo con*/ 
	int i,j,min;							/* la posición i. */

	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(v[i] < v[min])
				min = j;
		}

		Intercambia(&v[i],&v[min]);
	}
}

void Anyade(int v[],int *n, int elem){					/* Añade un elemento al array, actualiza su número de elementos útiles y posteriormente lo ordena por selección */
	v[*n] = elem;
	*n = *n + 1;
	SelectionSort(v,*n);
}

Conjunto1000 Interseccion(Conjunto1000 a, Conjunto1000 b){				/* Devuelve la intersección de dos conjuntos, compara los dos conjuntos y selecciona aquellos elementos comunes */
	Conjunto1000 interseccion;
	int i;

	interseccion.num_elem = 0;
	for(i=0;i<a.num_elem;i++){
		if(PerteneceP(b.elementos,b.num_elem,a.elementos[i]))
			Anyade(interseccion.elementos,&interseccion.num_elem,a.elementos[i]);
	}

	return interseccion;
}

Conjunto1000 Diferencia(Conjunto1000 a, Conjunto1000 b){				/* A-B en términos conjuntistas */
	Conjunto1000 diferencia;
	int i;										/* Algoritmo: recorre el array a, si a no pertenece b se añade al conjunto diferencia */

	diferencia.num_elem = 0;
	for(i=0;i<a.num_elem;i++){
		if(!PerteneceP(b.elementos,b.num_elem,a.elementos[i]))
			Anyade(diferencia.elementos,&diferencia.num_elem,a.elementos[i]);
	}

	return diferencia;
}

Conjunto1000 Union(Conjunto1000 a, Conjunto1000 b){					/* Devuelve la unión de dos conjuntos */ 
	Conjunto1000 unionz, diferencia_a_b, diferencia_b_a, interseccion;		
	int i;

	diferencia_a_b = Diferencia(a,b);
	diferencia_b_a = Diferencia(b,a);
	interseccion = Interseccion(a,b);

	for(i=0;i<diferencia_a_b.num_elem;i++)
		Anyade(unionz.elementos,&unionz.num_elem,diferencia_a_b.elementos[i]);

	for(i=0;i<diferencia_b_a.num_elem;i++)
		Anyade(unionz.elementos,&unionz.num_elem,diferencia_b_a.elementos[i]);

	for(i=0;i<interseccion.num_elem;i++)
		Anyade(unionz.elementos,&unionz.num_elem,interseccion.elementos[i]);

	return unionz;
}






	




