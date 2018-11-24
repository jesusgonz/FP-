#include <stdio.h>
#include <stdlib.h>

#define N 100
#define MAX 1000

void LeeMatriz(int matriz[][N], int util){
	int i,j;

	for(i=0;i<util;i++){
		for(j=0;j<util;j++){
			scanf("%d",&matriz[i][j]);
		}
	}

}

int AparecenTodos(int matriz[][N], int util){
	int i,j;
	int aparecen = 1;
	int no_aparecido = 0;
	int apariciones[MAX];

	for(i=0;i<util*util;i++){
		apariciones[i] = 0;
	}

	for(i=0;i<util && aparecen;i++){
		for(j=0;j<util && aparecen;j++){
			if(1 <= matriz[i][j] && matriz[i][j] <= util*util){
				if(apariciones[matriz[i][j]-1] == 0){
					apariciones[matriz[i][j]-1] = 1;
				} else 
					aparecen = 0;
			} else
				aparecen = 0;
		}
	}

	return aparecen;
}

int SumaFila(int matriz[][N], int util, int fil){
	int j;
	int sum = 0;

	for(j=0;j<util;j++){
		sum += matriz[fil][j];
	}

	return sum;
}

int SumaColumna(int matriz[][N], int util, int col){
	int i;
	int sum = 0;

	for(i=0;i<util;i++){
		sum += matriz[i][col];
	}

	return sum;
}

int SumaDiagonalPrincipal(int matriz [][N], int util){
	int i;
	int sum = 0;

	for(i=0;i<util;i++){
		sum += matriz[i][i];
	}
	
	return sum;
}

int SumaDiagonalSecundaria(int matriz[][N], int util){
	int i,j;
	int sum = 0;
	
	for(i=0,j=util-1;i<util;i++,j--){
		sum += matriz[i][j];
	}

	return sum;
}

int CoincidenSumas(int matriz[][N], int util){
	int coinciden = 1;
	int i;
	int j;
	
	int suma_fil = SumaFila(matriz,util,0);
	
	for(i=1;i<util && coinciden;i++){
		if(suma_fil != SumaFila(matriz,util,i)){
			coinciden = 0;
		}
	}

	for(j=0;j<util && coinciden;j++){
		if(suma_fil != SumaColumna(matriz,util,j))
			coinciden = 0;
	}

	if(coinciden){
		if(suma_fil == SumaDiagonalPrincipal(matriz,util) && SumaDiagonalPrincipal(matriz,util) == SumaDiagonalSecundaria(matriz,util))
			return 1;
		else
			return 0;
	} else
		return 0;
}


int MatrizMagica(int matriz[][N], int util){
	if(CoincidenSumas(matriz,util) && AparecenTodos(matriz,util))
		return 1;
	else
		return 0;
}

int main(){
	int matriz[N][N];
	int util = 5;

	LeeMatriz(matriz,util);
	
	if(MatrizMagica(matriz,util))
		printf("ES MAGICA");
	else
		printf("NI MUCHO MENOS");

	return 0;
}

			















































			
