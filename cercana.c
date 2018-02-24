#include <stdio.h>
#include <math.h>

#define NCOLUMNAS 100
#define MAX 100
#define ERROR -1

float DistanciaEuclideaRN(const int x[], const int y[], int n){
	float sum = 0.0;
	int i;

	for(i=0;i<n;i++){
		sum += (x[i]-y[i])*(x[i]-y[i]);
	}

	return sqrt(sum);
}

void LeeVector(int v[], int n){
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&v[i]);

}

void LeeMatriz(int v[][NCOLUMNAS], int m, int n){
	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&v[i][j]);
		}
	}

}

int DistanciaMenorVectorFila(const int v[], const int m[][NCOLUMNAS], const int v_filas[], int nfilas, int util_fil,int n){
	if(nfilas <= util_fil){
		int i,fila_minima; 
		float d_minima;

		fila_minima = 0;
		d_minima = DistanciaEuclideaRN(v,m[v_filas[0]],n);

		for(i=1;i<nfilas;i++){
			if(DistanciaEuclideaRN(v,m[v_filas[i]],n) < d_minima){
				fila_minima = v_filas[i];
				d_minima = DistanciaEuclideaRN(v,m[v_filas[i]],n);
			}
		}

		return fila_minima;
	} else
		return ERROR;

}

int main(){
	int util_col, util_fil, nfilas;
	int matriz[MAX][NCOLUMNAS];
	int vector[MAX];
	int vector_filas[MAX];
	int fila_minima;


	scanf("%d",&util_col);
	LeeVector(vector,util_col);
	scanf("%d",&nfilas);
	LeeVector(vector_filas,nfilas);
	scanf("%d",&util_fil);
	LeeMatriz(matriz,util_fil,util_col);

	fila_minima = DistanciaMenorVectorFila(vector,matriz,vector_filas,nfilas,util_fil,util_col);

	printf("%d",fila_minima);

	return 0;
}










