#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 300

int EsPrimo(int n){
	int es_primo = 1;
	int i;

	for(i=n/2;i>sqrt(n) && es_primo;i--){
		if(n%i == 0){
			es_primo = 0;
		}
	}

	return es_primo;
}

int* DescomposicionPrimo(int n,int *utiles){
		int p = 2;
		int *v = (int*)malloc(sizeof(int)*MAX);
		int i = 0;
		
		while(n != 1 || p < sqrt(n)){
			while(n%p==0){
				v[i] = p;
				n /= p;
				i++;
			}
			p++;
			while(!EsPrimo(p))
				p++;
		}

		*utiles = i;
		v = (int*)realloc(v,sizeof(int)*(*utiles));
		

		return v;
	
}		

void ImprimeArray(int v[],int n){
	int i;

	for(i=0;i<n;i++){
		printf("%d ",v[i]);
	}
}
	

int main(void){
	int num;
	int utiles;
	int *desc_primos;

	scanf("%d",&num);
	
	desc_primos = DescomposicionPrimo(num,&utiles);

	ImprimeArray(desc_primos,utiles); 
	return 0;
}

	


	




