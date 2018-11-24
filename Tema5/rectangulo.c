#include <stdio.h>

#define MAX 20

struct Rectangulo{							/// Declaración de la estructura
	float base;
	float altura;
};

typedef struct Rectangulo Rectangulo;					/// Declaración del tipo rectángulo

float Perimetro(Rectangulo a){						/// Calcula el perímetro
	return a.base*2+a.altura*2;
}

float Area(Rectangulo a){						/// Calcula el área
	return a.base*a.altura;
}

int RectanguloMayorP(Rectangulo a, Rectangulo b){			/// Clasifica los rectángulos por el área, true si a < b, false en caso contrario. 
	float area_a = Area(a);
	float area_b = Area(b);

	return area_a < area_b;

}

int RectangulosIdenticosP(Rectangulo a, Rectangulo b){			/// Devuelve si true si ambos rectángulos tienen igual área y mismo perímetro
	return (Area(a) == Area(b) && Perimetro(a) == Perimetro(b));
}

void IntercambiaRectangulos(Rectangulo *a, Rectangulo *b){		/// Intercambia dos rectángulos con el paso por referencia
	Rectangulo aux;
	aux.base = a->base;
	aux.altura = a->altura;

	a->base = b->base;
	a->altura = b->altura;
	
	b->base = aux.base;
	b->altura = aux.altura;

}

void ImprimeRectangulo(Rectangulo a){
	printf("\nAltura: %f\nBase: %f\nArea: %f\nPerimetro %f\n",a.altura,a.base,Area(a),Perimetro(a));
}

void OrdenaRectangulos(Rectangulo v[], int n){				/// Ordenación por selección atendiendo a la clave área menor
	int i,j;
	int min;

	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(RectanguloMayorP(v[j],v[min]))
				min = j;
		IntercambiaRectangulos(&v[min],&v[i]);
		}
	}
}


int main(void){
	Rectangulo a;
	Rectangulo b;
	Rectangulo c;
	Rectangulo d;
	Rectangulo v[MAX];
	int i;

	a.base = 2.23;
	a.altura = 1.6;

	b.base = 0.02;
	b.altura = 0.01;

	c.base = 45.6;
	c.altura = 24.57;

	d.base = 134;
	d.altura = 125;

	v[0] = c;
	v[1] = d;
	v[2] = a;
	v[3] = b;


	OrdenaRectangulos(v,4);
	for(i=0;i<4;i++)
		ImprimeRectangulo(v[i]);
	

	return 0;
}


