#include <stdio.h>									/// Biblioteca de E/S
#include <math.h>									/// Biblioteca de recursos matemáticos
#include <string.h>									/// Biblioteca de recursos para Cadenas-C


#define MAX 20 										/// Constante de preprocesado

struct Ciudad{										/// Declaración de la estructura
	float x;
	float y;
	char nombre[50];
};
	
typedef struct Ciudad Ciudad;								/// Declaración del tipo Ciudad

int CiudadEnVP(Ciudad v[], int n, const char *cad){					/// Recorre un array de ciudades, si la cadena de entrada coincide con el nombre de una ciudad devuelve true,
	int i, encontrado = 0;								/// en caso contrario devuelve false

	for(i=0;i<n && !encontrado;i++){
		if(strcmp(v[i].nombre,cad) == 0)
			encontrado = 1;
	}

	return encontrado;
}

int PosicionEnV(Ciudad v[], int n, const char *cad){					/// Devuelve la posición en la que se encuentra una ciudad determinada por su nombre
	int i, encontrado = 0;								/// en caso de que no esté devuelve una posición inválida(-1)
	int posicion = -1;

	for(i=0;i<n && !encontrado;i++){
		if(strcmp(v[i].nombre,cad) == 0){
			encontrado = 1;
			posicion = i;
		}
	}

	return posicion;
}


void Intercambiar(Ciudad *a, Ciudad *b){						/// Intercambia dos ciudades valiéndose del paso por referencia
	Ciudad aux;
	aux = *b;
	*b = *a;
	*a = aux;
}

double DistanciaCiudades(Ciudad a, Ciudad b){						/// Calcula la distancia entre dos ciudades
	double distancia = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));	/// Algoritmo: distancia euclídea en R2
	return distancia;
}


void Ordenar(Ciudad v[], int n, const char *cad){					/// Ordena un array de ciudades a partir del nombre de una ciudad que pertenece al array, en caso de que no
	int posicion, min, i,j;								/// pertenezca no hace nada
	double d_min;
	if(CiudadEnVP(v,n,cad)){							/// Algoritmo: ordenación por selección a partir de la clave distancia menor a la ciudad definida por la cadena 
		posicion = PosicionEnV(v,n,cad);
		Intercambiar(&v[0],&v[posicion]);
	
		for(i=1;i<n;i++){
			min = i;
			d_min = DistanciaCiudades(v[0],v[min]);
			for(j=i+1;j<n;j++){
				if(DistanciaCiudades(v[0],v[j]) < d_min){
					min = j;
					d_min = DistanciaCiudades(v[0],v[min]);
				}
			}
			
			Intercambiar(&v[i],&v[min]);
		}
	}
}


int main(void){
	Ciudad v[MAX];
	int i; 
	int n = 5;

	for(i=0;i<n;i++){
		printf("\nIntroduzca las coordenadas de la ciudad(x,y) y su nombre: ");
		scanf("%f",&v[i].x);
		scanf("%f",&v[i].y);
		scanf("%s",v[i].nombre);
	}

	Ordenar(v,n,"Madrid");

	for(i=0;i<n;i++)
		printf("\n%f %f %s",v[i].x,v[i].y,v[i].nombre);

	return 0;

}








		


