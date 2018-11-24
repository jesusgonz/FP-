#include <stdio.h>

int MCM(int a, int b){
	int i=0;
	if (a > b){
		if (a % b == 0)
			return b;
		else
			for(i=0;i<=a/2;i++){
				if(a%i==0)
					return i;
			} return a*b;
			
	} else if (b > a){
		if (b % a == 0)
			return a;
		else
			for(i=0;i<=b/2;i++){
				if(b%i==0)
					return i;
			} return a*b;
	} else return a; 		/// Trivialmente, a==b 
}

int main(){
	int a, b, mcm;
	printf("Introduzca dos numeros enteros: ");
	scanf("%d",&a);
	scanf("%d",&b);

	printf("El mcm de los numeros introducidos es: ");
	printf("%d",MCM(a,b));
}
		 


		 
