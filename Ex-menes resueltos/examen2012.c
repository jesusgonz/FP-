#include <stdio.h>

#define MAX 100

int SumaArrayEntero(int v[], int n){
	int i;
	int sum = 0;

	for(i=0;i<n;i++)
		sum += v[i];

	return sum;
}

		

int SumaKDigitos(int n, int k){
	int digitos[MAX];
	int n_digitos = 0;
	int suma;

	while(n/10 != 0){
		digitos[n_digitos-1] = n%10;
		n_digitos++;
		printf("NDIGITOS: %d DIGITO: %d \n",n_digitos,n%10);
		n = n/10;
	}

	digitos[n_digitos-1] = n%10;
	
	if(k >= n_digitos){
		suma = SumaArrayEntero(digitos,n_digitos);
	} else
		suma = SumaArrayEntero(digitos,k);

	return suma;
}


int main(){
	int n,k, suma;

	scanf("%d",&n);
	scanf("%d",&k);

	suma = SumaKDigitos(n,k);

	printf("%d",suma);
	

	return 0;
}

	
