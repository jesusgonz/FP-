#include <stdio.h>
#include <errno.h>

struct Complejo{							/// Declaración de la estructura
	double real;
	double imaginario; 
};

typedef struct Complejo Complejo;					/// Declaración de Complejo como un tipo, evitando usar struct Complejo 

Complejo Suma(Complejo a, Complejo b){					/// Entrada: 2 números complejos, Salida: un número complejo que es la suma de los dos de la entrada
	Complejo suma;							

	suma.real = a.real + b.real;
	suma.imaginario = a.imaginario + b.imaginario;

	return suma;
}

Complejo Resta(Complejo a, Complejo b){					/// Análogo al caso suma
	Complejo resta;

	resta.real = a.real - b.real;
	resta.imaginario = a.imaginario - b.imaginario;

	return resta;
}

Complejo Multiplicacion(Complejo a, Complejo b){			/// Paramétros: dos números complejos, Salida: un número complejo resultado de la multiplicación de la entrada
	Complejo multiplicacion;					/// Algoritmo: multiplicación rectangular de complejos, Re=Re(a)*Re(b)-Im(a)*Im(b)
									/// Im=Re(a)*Im(b)+Im(a)*Re(b)
	multiplicacion.real = a.real * b.real - a.imaginario * b.imaginario;
	multiplicacion.imaginario = a.real * b.imaginario + a.imaginario * b.real;

	return multiplicacion; 
}

Complejo Division(Complejo a, Complejo b){				/// Parámetros: dos complejos, Salida: un número complejo resultado de la división de la entrada
	Complejo division = {-1,-1};					/// Algoritmo: si el denominador no es 0, Re=(Re(a)+Re(b))*(Im(a)*(Im(b))/(Re(b)^2+Im(b)^2)
									/// Im=(Im(a)*Re(b)-Re(a)*Im(b))/(Re(b)^2+Im(b)^2)
	if(b.real != 0 && b.imaginario != 0){
		division.real = ((a.real + b.real)*(a.imaginario*b.imaginario))/(b.real*b.real + b.imaginario*b.imaginario);
		division.imaginario = (a.imaginario * b.real - a.real*b.imaginario)/(b.real*b.real + b.imaginario*b.imaginario);
	} 


	return division;
	

}

void ImprimirComplejo(Complejo a){
	if(a.imaginario >= 0)
		printf("%lf + %lfi\n",a.real,a.imaginario);
	else
		printf("%lf %lfi\n",a.real,a.imaginario);
}

int main(void){
	Complejo a, b, suma, resta, multiplicacion, division;

	a.real = 5;
	a.imaginario = -1;
	b.real = -2;
	b.imaginario = 4;

	suma = Suma(a,b);
	resta = Resta(a,b);
	multiplicacion = Multiplicacion(a,b);
	division = Division(a,b);

	ImprimirComplejo(suma);
	ImprimirComplejo(resta);
	ImprimirComplejo(multiplicacion);
	ImprimirComplejo(division);

	return 0;
}


	


