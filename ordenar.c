#include <stdio.h>

#define NFIL 100
#define NCOL 100

void LeeMatriz(int m[][NCOL], int nfil, int ncol){
	int i,j;

	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			scanf("%d",&m[i][j]);
		}
	}
}

void IntercambiaColumna(int m[][NCOL], int nfil, int ncol, int col_1, int col_2){
	if((0<=col_1 && col_1 < ncol) && (0<=col_2 && col_2 < ncol)){
		int aux, i;

		for(i=0;i<nfil;i++){
			aux = m[i][col_1];
			m[i][col_1] = m[i][col_2];
			m[i][col_2] = aux;

		}
	}
}

float MediaAritmeticaColumna(int m[][NCOL], int nfil, int ncol, int col){
	if(0<=col && col < ncol){
		int i;
		int sum = 0;
		float media;

		for(i=0;i<nfil;i++){
			sum += m[i][col];
		}

		media = sum/(float)nfil;

		return media;
	} else
		return -1;
}

void OrdenaColumnasMatriz(int m[][NCOL], int nfil, int ncol){
	int i, j, min;

	for(i=0;i < ncol-1;i++){
		min = i;
		for(j=i+1;j<ncol;j++){
			if(MediaAritmeticaColumna(m,nfil,ncol,j)<MediaAritmeticaColumna(m,nfil,ncol,min))
				min = j;
		}

		IntercambiaColumna(m,nfil,ncol,i,min);
	}
}

void ImprimeMatriz(const int m[][NCOL], int nfil, int ncol){
	int i,j;

	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			printf("%d ",m[i][j]);
		}

		printf("\n");
	}
}

int main(){
	int m[NFIL][NCOL];
	int util_fil, util_col;

	scanf("%d",&util_fil);
	scanf("%d",&util_col);
	LeeMatriz(m,util_fil,util_col);

	OrdenaColumnasMatriz(m,util_fil,util_col);

	ImprimeMatriz(m,util_fil,util_col);

	return 0;
}


	

