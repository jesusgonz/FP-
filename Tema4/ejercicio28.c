#define MAX 20 

void MatrizProducto(const int m1[][MAX], const int m2[][MAX], int m, int n, int producto[][MAX]){
	int i,j;
	int sumatorio = 0;

	for(i=0;i<m;i++){
		sumatorio = 0;

		for(j=0;j<n;j++){
			sumatorio += m1[i][j]*[j][i];
		}
		
		producto[i][j] = sumatorio;
	}
}
