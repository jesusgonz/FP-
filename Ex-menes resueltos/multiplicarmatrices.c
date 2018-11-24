#include <stdio.h>

#define N 100

void LeeMatriz(int matriz[][N], int m, int n){
	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriz[i][j]);
		}
	}
}

void ProductoMatrices(int producto[][N],int m1[][N], int m2[][N], int m, int n){
	int i,j,k;

	for(i=0;i<m;i++){
		for(k=0;k<m;k++){
			producto[i][k] = 0;
			for(j=0;j<n;j++){
				producto[i][k] += m1[i][j] * m2[j][k];
			}
		}
	}
}

void ImprimeMatriz(int matriz[][N], int m, int n){
	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}



int main(){
	int m1[N][N];
	int m2[N][N];
	int m, n;
	int p[N][N];

	scanf("%d",&m);
	scanf("%d",&n);
	LeeMatriz(m1,m,n);
	LeeMatriz(m2,n,m);

	ProductoMatrices(p,m1,m2,m,n);

	ImprimeMatriz(p,m,m);

	return 0;
}

	
