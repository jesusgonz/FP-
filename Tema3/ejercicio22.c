#include <stdio.h>

#define TERMINADOR 0 

int EsPar(int n){
	return (n % 2 == 0);
}

int main(void){
	int n;
	int sumaimpares = 0;
	int sumapares = 0; 

	scanf("%d",&n);		/// Lectura anticipada

	while(n!=TERMINADOR){
		if(EsPar(n))
			sumapares += n;
		else
			sumaimpares += n;
	scanf("%d",&n);
	}

	printf("La suma de los numeros pares es: %d", sumapares);
	printf("\nLa suma de los numeros impares es: %d", sumaimpares);

	return 0;
}
		
		

