#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int EsPerfecto(int n){
	int s = 0;
	int i;

	for(i=1;i<=(n/2);i++){
		if(n%i==0){
			s+=i;
		}
	}

	return(s==n);
}

int main(void){
	int i; 
	
	printf("Lista de numeros perfectos: ");

	for(i=1;i!=MAX;i++){
		if(EsPerfecto(i)){
			printf("\n %d",i);
		}
	}
	return 0;
}
