#include <stdio.h>

int MCD(int m, int n){ 				/// Función recursiva que devuelve el mcd
	int r;					/// Entrada: m, n enteros con m > n
	if(m%n==0)				/// Salida: mínimo común divisor de m y n
		return n;			/// Algoritmo: Si el resto entre m y n devuelve n, en caso contrario vuelve a llamar la función 
	else{
		r= m%n;
		return MCD(n,r);
	}
}

int main(void){
	int a, b, mcd;
	a = 15;
	b = 3;

	mcd = MCD(a,b);

	printf("%d ",mcd);
	
	return 0;
}
