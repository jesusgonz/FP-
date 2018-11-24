#include <stdio.h>
#include <stdlib.h>

struct Punto2D{
	double x;
	double y;
};

struct Nodo{
	struct Punto2D punto;
	struct Nodo *sigpunto;
};

typedef struct Nodo* Poligono;

int NumLados(Poligono p){
	int i=1;

	struct Nodo* cursor = p->sigpunto;
	while(cursor != p){
		cursor = cursor->sigpunto;
		i++;
	}

	return i;
}


void CreaTriangulo(Poligono *p, Punto2D p1, Punto2D p2, Punto2D p3){
	struct Nodo* lado_1, lado_2, lado_3;

	lado_1 = (struct Nodo*)malloc(sizeof(struct Nodo));
	lado_2 = (struct Nodo*)malloc(sizeof(struct Nodo));
	lado_3 = (struct Nodo*)malloc(sizeof(struct Nodo));

	lado_1->punto = p1;
	lado_2->punto = p2;
	lado_3->punto = p3;

	lado_1->sigpunto = lado_2;
	lado_2->sigpunto = lado_3:
	lado_3->sigpunto = lado_1;

	*p = lado_3; 
}


void BorraListaCircular(struct Nodo **inicio){
	struct Nodo* actual = *inicio;
	struct Nodo* siguiente = actual->sigpunto;

	*inicio = NULL;

	while(siguiente != NULL){
		free(actual);
		actual = siguiente;
		siguiente = actual->sigpunto;
	}

}



		
	

