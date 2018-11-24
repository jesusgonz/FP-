#include <stdio.h>
#include <string.h>

#define MAX 20

struct DVD {
	int codigo;
	char titulo[257];
	int agno;
};

typedef struct DVD DVD;

int TituloMenor(DVD a, DVD b){
	int valor_bool;
	
	valor_bool = strcmp(a.titulo, b.titulo);

	if(valor_bool > 0)
		return 1;
	else
		return 0;
}

void IntercambiaDVD(DVD *a, DVD *b){
	DVD aux;

	aux = *a;
	*a = *b;
	*b = aux;
}


void OrdenaPorTitulo(DVD v[], int n){
	int i,j,min;

	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(TituloMenor(v[min],v[j]))
				min = j;
		}

		IntercambiaDVD(&v[i],&v[min]);
	}
}



void AnyadeOrdenado(DVD v[], int *n, DVD a){
	int index = 0;
	int i;
	
	while(TituloMenor(v[index],a))
		index++;

	for(i=*n;i>index;i--)
		v[i] = v[i-1];

	v[index] = a;
	*n = *n +1;	
}

int DevuelveCodigo(DVD v[], int l, int r, int n, const char *cad){
	if(n > r){
		if(r >= l){
			int medio = l + (r-l)/2;

			if(strcmp(v[medio].titulo,cad) == 0){
				return v[medio].codigo;

			} else if(strcmp(v[medio].titulo,cad) > 0){
				return DevuelveCodigo(v,l,medio-1,n,cad);

			} else
				return DevuelveCodigo(v,medio+1,r,n,cad);
		}
	}

	return -1;
}

void ImprimeDVD(DVD a){
	printf("Codigo: %d\nNombre: %s\n",a.codigo,a.titulo);
}


int main(void){
	DVD saw, scream, torrente, tmsc;
	int util = 0;
	int i;
	int posicion = -1;
	DVD v[MAX];

	saw.codigo = 1997;
	scream.codigo = 1998;
	torrente.codigo = 2000;
	tmsc.codigo = 2010;

	strcpy(saw.titulo,"Saw");
	strcpy(tmsc.titulo,"Tresmetrossobreelcielo");
	strcpy(torrente.titulo,"Torrente");
	strcpy(scream.titulo,"Scream");

	AnyadeOrdenado(v,&util,saw);
	AnyadeOrdenado(v,&util,torrente);
	AnyadeOrdenado(v,&util,tmsc);
	AnyadeOrdenado(v,&util,scream);

	OrdenaPorTitulo(v,util);

	posicion = DevuelveCodigo(v,0,util-1,util,"Torrente");

	printf("\n%d\n",posicion);
	for(i=0;i<util;i++)
		ImprimeDVD(v[i]);
	

	return 0;
}






		

	
			


