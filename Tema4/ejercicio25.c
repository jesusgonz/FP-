#include <stdio.h>

#define MAX 20

///*************************************************///
/// Entrada: dos matrices de enteros
/// Salida: 1 si son iguales, 0 si son diferentes
/// Precondición: se presupone que ambas son mxn 
///************************************************///

int MatrizIgualP(const int m1[][MAX], const int m2[][MAX], int m, int n){
	int i,j;
	int son_iguales = 1;

	for(i=0;i<m && son_iguales;i++){
		for(j=0;j<n && son_iguales;j++){
			if(m1[i][j] != m2[i][j])
				son_iguales = 0;
		}
	}

	return son_iguales;
}

int main(void){
	int m1[MAX][MAX];
	int m2[MAX][MAX];
	int iguales; 

	m1[0][0] = -1;
	m2[0][0] = 1;
	m1[0][1] = 2;
	m2[0][1] = 2;

	if(MatrizIgualP(m1,m2,1,2))
		printf("Son iguales");
	else
		printf("No son iguales");

	return 0;
}
	
