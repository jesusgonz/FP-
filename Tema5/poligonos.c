#include <stdio.h>
#include <math.h>

struct Punto{
	float x;
	float y;
};

typedef struct Punto Punto;

struct Poligono{
	Punto ptos[100];
	int num_ptos;
};

typedef struct Poligono Poligono;

/// Punto InteriorPunto(const Poligono *p); ////

float DistanciaEuclidea(const Punto *p1, const Punto *p2){
	return sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));
}

float AreaTriangulo(const Punto *p1, const Punto *p2, const Punto *p3){
	float s1,s2,s3,f,area;

	s1 = DistanciaEuclidea(p1,p2);
	s2 = DistanciaEuclidea(p2,p3);
	s3 = DistanciaEuclidea(p1,p3);

	f = (s1+s2+s3)/2;

	area = sqrt(f*(f-s1)*(f-s2)*(f-s3));

	return area;
}

float AreaPoligono(const Poligono *p){
	Punto interior;
	interior.x = 0.0;
	interior.y = 0.0;
	float area = 0;
	int n = p->num_ptos;
	int i;

	area += AreaTriangulo(&p->ptos[n-1],&p->ptos[0],&interior);

	for(i=0;i<n-1;i++){
		area += AreaTriangulo(&p->ptos[i],&p->ptos[i+1],&interior);
	}

	return area; 
}

int main(){
	return 0;
}

