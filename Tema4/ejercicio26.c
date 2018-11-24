#include <stdio.h>

#define MAX 20

///*********************************************///
/// Entrada: una matriz de enteros y su dimensión
/// Salida: 1 si la matriz de entrada es simétrica, 0 en caso contrario 
///**********************************************///

int SimetricaP(const int m[][MAX], int n){
	int es_simetrica = 1;
	int i,j;

	for(i=0;i<n && es_simetrica;i++){
		for(j=0;j<n && es_simetrica;j++){
			if(m[i][j] != m[j][i])
				es_simetrica = 0;
		}
	}

	return es_simetrica;
}


	
