#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long double G = 6.6 * pow(10,-11);

long double FuerzaGravitacional(double d, double m1, double m2){ return (G*m1*m2)/(d*d); }

int main(){
	double d, m1, m2,f;
	printf("Introduzca la distancia a la que se encuentran los cuerpos, y sus respectivas masas: ");
	
	scanf("%f",&d);	
	scanf("%f",&m1);
	scanf("%f",&m2);

	f = FuerzaGravitacional(d,m1,m2);

	printf("La fuerza gravitacional a la que están sometidos los cuerpos es: ");
	printf("%f",f);
}


