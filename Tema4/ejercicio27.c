#include <stdio.h>

#define MAX 20 

void ImprimeMatriz(const int m1[][MAX], int m, int n){
	int i,j;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",m1[i][j]);
		}
	}
}

void MatrizSuma(const int m1[][MAX], const int m2[][MAX], int m, int n, int resultado[][MAX]){
	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			resultado[i][j] = m1[i][j] + m2[i][j];
		}
	}
}	
