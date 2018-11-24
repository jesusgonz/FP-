#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int info;
	struct Nodo *sig;
};

void CrearLista(struct Nodo **inicio, int dat){
	*inicio = (struct Nodo*)malloc(sizeof(struct Nodo));
	(*inicio)->sig = NULL;
	(*inicio)->info = dat;
}


void InsertaNodo(struct Nodo **inicio, int dat, int pos){
	if(pos == 0){
		struct Nodo *p=(struct Nodo*)malloc(sizeof(struct Nodo));
		p->info = dat;
		p->sig = *inicio;
		*inicio = p;
	} else {
		int i = 0;
		struct Nodo *a_insertar = *inicio;
		struct Nodo *p=(struct Nodo*)malloc(sizeof(struct Nodo));
		p->info = dat;
		p->sig = NULL;

		while(a_insertar->sig != NULL && i < pos){
			a_insertar = a_insertar->sig;
			i++;
		}

		if(a_insertar->sig == NULL){
			a_insertar->sig = p;
		} else {
			p->sig = a_insertar->sig;
			a_insertar->sig = p;
		}
	}
}

void InsertaNodoFinal(struct Nodo *inicio, int dat){
	struct Nodo *p=(struct Nodo*)malloc(sizeof(struct Nodo));
	struct Nodo *a_insertar = inicio;
	p->info = dat;
	p->sig = NULL;

	while(a_insertar->sig != NULL){
		a_insertar = a_insertar->sig;
	}

	a_insertar->sig = p;
}


void EliminaLista(struct Nodo **inicio){
	struct Nodo *actual;

	while(*inicio != NULL){
		actual = (*inicio)->sig;
		free(*inicio);
		*inicio = actual;
	}
}

void ImprimeLista(struct Nodo *inicio){
	struct Nodo *actual = inicio;

	while(actual != NULL){
		printf("%d ",actual->info);
		actual = actual->sig;
	}
}

void IntercambiaInt(int *a, int *b){
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void OrdenaBurbuja(struct Nodo* inicio){
	struct Nodo* cursor = inicio;
	int cambio = 1;

	while(cambio){
		cambio = 0;
		cursor = inicio;
		while(cursor->sig != NULL){
			if(cursor->info > cursor->sig->info){
				IntercambiaInt(&(cursor->info),&(cursor->sig->info));
				cambio = 1;
			}
			cursor = cursor->sig;
		}
	}
}
	

			
int main(void){
	struct Nodo *inicio = NULL;
	int i;
	int num;

	CrearLista(&inicio,0);
	for(i=1;i<16;i++){
		scanf("%d",&num);
		InsertaNodoFinal(inicio,num);
	}


	OrdenaBurbuja(inicio);
	
	ImprimeLista(inicio);
	EliminaLista(&inicio);
	
	return 0;

}













