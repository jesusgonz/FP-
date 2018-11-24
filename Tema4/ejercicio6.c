#include <stdio.h>			/// Biblioteca de I/0

#define MAX 100				/// Número de elementos máximo del vector

///**********************************************************************************///
/// Param: v: devuelve el array de los elementos mezclados y ordenados 
///        p1 y p2: array sobre los que se realiza la comparación de elementos
///	   util_p1 y util_p2: número de elementos de cada array respectivamente
///        *util_v: puntero a entero que devuelve la dirección de memoria de la variable que almacena el número de elementos de v(si la función no comete ningún error *util_v = util_p1 + util_p2)
/// Algoritmo: se declaran dos índices para cada array respectivamente, se recorre el vector mientras los dos índices no sean util_p1 y util_p2 respectivamente, posteriormente se compara que elemento es mayor y se compara que el índice sea menor que útil para no dar una posición de lectura errónea. 

void InsertarOrdenados(int v[], const int p1[], const int p2[], int util_p1, int util_p2, int *util_v){		
	int indice_p1 = 0, indice_p2 = 0;

	while((indice_p1 < (util_p1)) || (indice_p2 < (util_p2))){
		if((p1[indice_p1] < p2[indice_p2]) && (indice_p1 < (util_p1)) ){
			v[*util_v] = p1[indice_p1];
			(*util_v)++;
			indice_p1++;
		} else if ((indice_p2 < (util_p2))){
			v[*util_v] = p2[indice_p2];
			(*util_v)++;
			indice_p2++;
		} else {
			v[*util_v] = p1[indice_p1];
			(*util_v)++;
			indice_p1++;
		}
		
	}
}

void ImprimeArray(const int v[], int util){
	int i;
	for(i=0;i<util;i++)
		printf("%d \n",v[i]);
}

int main(){
	int p1[MAX]={1,3,5,7,9};
	int p2[MAX]={2,4,6};
	int util_p1 = 5;
	int util_p2 = 3;
	int v[MAX];
	int util = 0;

	InsertarOrdenados(v,p1,p2,util_p1,util_p2,&util);
	ImprimeArray(v,util);

	return 0;
}

			
