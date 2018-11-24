#include <stdio.h>


int NDigitos(int num){
	int n=0;
	unsigned int i = (unsigned int)num; 	/// Casting a unsigned para no tener problemas en las divisiones siguientes 

	while(i>0){
		i /= 10;
		n++;
	}

	return n;
}

int main(){
	int num, digitos;

	printf("Introduzca un numero entero: ");
	scanf("%d",&num);


	digitos = NDigitos(num);
	printf("El numero de digitos de dicho numero es: %d",digitos);
	printf("\n");

	return 0;
} 

	
