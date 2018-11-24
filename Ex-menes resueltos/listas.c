#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo *sig;
};

void InsertarNodo(struct Nodo **inicio, int dat){
	struct Nodo *p;

	p = (struct Nodo*)malloc(sizeof(struct Nodo));
	p->dato = dat;
	p->sig = *inicio;

	*inicio = p;
}

void InsertarNodoFinal(struct Nodo **inicio, int dat){
	struct Nodo *p;
	struct Nodo *final;

	p = (struct Nodo*)malloc(sizeof(struct Nodo));
	p->dato = dat;
	p->sig = NULL;

	final = *inicio;

	while(final->sig != NULL){
		final = final->sig;
	}

	final->sig = p;
}

void InsertarNodoPos(struct Nodo **inicio, int dat, int pos){
	if(pos == 0)
		InsertarNodo(inicio,dat);
	else {
		int n = 0;
		struct Nodo *p;
		struct Nodo *a_insertar;

		p = (struct Nodo*)malloc(sizeof(struct Nodo));
		p->dato = dat;
		p->sig = NULL;

		a_insertar = *inicio;

		while(a_insertar->sig != NULL && n < pos){
			a_insertar = a_insertar->sig;
			n++;
		}

		p->sig = a_insertar->sig;
		a_insertar->sig = p;
	}

}

void EliminaLista(struct Nodo **inicio){
	struct Nodo *actual;
	while(*inicio != NULL){
		actual = (*inicio)->sig;
		free(*inicio);
		*inicio = actual;
	}
}

void EliminaUltimoNodo(struct Nodo **inicio){
	struct Nodo *eliminar = *inicio;
	struct Nodo *modificar = *inicio;

	while((modificar->sig)->sig != NULL){
		modificar = modificar->sig;
	}

	eliminar = modificar->sig;
	free(eliminar);
	modificar->sig = NULL;

}

void EliminaNodo(struct Nodo **inicio, int pos){
	int n = 0;
	struct Nodo *eliminar = *inicio;
	struct Nodo *modificar = *inicio;

	if(pos==0){
		*inicio = (*inicio)->sig;
		free(eliminar);
	} else {
		while(modificar->sig != NULL && n+1 < pos){
			modificar = modificar->sig;
			n++;
		}

		if(modificar->sig != NULL){
			eliminar = modificar->sig;
			modificar->sig = eliminar->sig;
			free(eliminar);
		} else {
			EliminaUltimoNodo(inicio);
		}
	}

}

struct Nodo* BuscaNodo(struct Nodo *inicio, int key){
	struct Nodo *elemento = inicio;

	while(elemento != NULL && elemento->dato != key){
		elemento = elemento->sig;
	}

	return elemento;
}

void ImprimeLista(struct Nodo *inicio){
	while(inicio != NULL){
		printf("%d ",inicio->dato);
		inicio = inicio->sig;
	}

	printf("\n");
}

void ImprimeNodo(struct Nodo *p){
	if(p != NULL)
		printf("%d",p->dato);
	else
		printf("Puntero nulo");
}


int LongitudLista(struct Nodo *inicio){
	int n = 0;

	while(inicio != NULL){
		n++;
		inicio = inicio->sig;
	}

	return n;
}


void IntercambiaInt(int *a, int *b){
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void OrdenaListaBurbuja(struct Nodo *inicio){
	struct Nodo *cursor;
	int cambio = 1;

	if(inicio != NULL){
		cursor = inicio;

		while(cambio){
			cursor = inicio;
			cambio = 0;
			while(cursor->sig != NULL){
				if(cursor->dato > cursor->sig->dato){
					IntercambiaInt(&(cursor->dato),&(cursor->sig->dato));
					cambio = 1;
					
				} 
			cursor = cursor->sig;
			}
		}
	}
}

int main(void){
	struct Nodo *inicio = NULL;
	struct Nodo *buscado = NULL;

	InsertarNodo(&inicio,1);
	InsertarNodoFinal(&inicio,10);
	InsertarNodoFinal(&inicio,3);
	InsertarNodoFinal(&inicio,1);
	InsertarNodoFinal(&inicio,13);
	InsertarNodoPos(&inicio,100,4);


	ImprimeLista(inicio);
	OrdenaListaBurbuja(inicio);
	ImprimeLista(inicio);
	EliminaLista(&inicio);

	return 0;
}
