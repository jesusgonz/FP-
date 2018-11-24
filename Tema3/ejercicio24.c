#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CUADRADO 1
#define CIRCULO 2
#define TRIANGULO 3 

void MostrarMenu(){
	printf("Elija la figura a la que le quiere calcular el area: ");
	printf("\n 1.Cuadrado");
	printf("\n 2.Circulo");
	printf("\n 3.Triangulo \n");
}

void MensajeCuadrado(){
	printf("\nIntroduzca la longitud de un lado(m): ");
}

void MensajeCirculo(){
	printf("\nIntroduzca la longitud del radio(m): ");
}

void MensajeTriangulo(){
	printf("\nIntroduzca la longitud de la base y la altura(m): ");
}

void MensajeArea(float area){
	printf("\nEl area es: %f",area); printf("m");
}

float AreaCuadrado(float n){
	return n*n;
}

float AreaCirculo(float r){
	return M_PI*r*r;
}

float AreaTriangulo(float b, float h){
	return (b*h)/2;
}


int main(void){
	int eleccion;
	float area, longitud, altura, radio; 

	MostrarMenu();
	do{
		scanf("%d",&eleccion);
	} while((eleccion > 3) || (eleccion < 0));

	switch(eleccion){
		case CUADRADO:
			MensajeCuadrado();
			scanf("%f",&longitud);
			area = AreaCuadrado(longitud);
			MensajeArea(area);
			break;
		case CIRCULO:
			MensajeCirculo();
			scanf("%f",&radio);
			area = AreaCirculo(radio);
			MensajeArea(area);
			break;
		case TRIANGULO:
			MensajeTriangulo();
			scanf("%f",&longitud);
			scanf("%f",&altura);
			area = AreaTriangulo(longitud,altura);
			MensajeArea(area);
			break;
	}

	return 0;

}



	
			
			
			
	
