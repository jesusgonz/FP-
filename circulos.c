#include <stdio.h>

#define MAX 100

struct Punto{
	int x;
	int y;
};

struct Circulo{
	struct Punto centro;
	int radio;
};

void LeePunto(struct Punto *p){
	scanf("%d",&p->x);
	scanf("%d",&p->y);
}

void LeeVectorCirculos(struct Circulo v[], int n){
	int i;

	for(i=0;i<n;i++){
		LeePunto(&v[i].centro);
		scanf("%d",&v[i].radio);
	}
}

int CirculoContienePunto(const struct Circulo circulo, const struct Punto punto){
	return ((((punto.x - circulo.centro.x)*(punto.x - circulo.centro.x))+((punto.y - circulo.centro.y)*(punto.y - circulo.centro.y))) <= (circulo.radio*circulo.radio));
}

void AnyadePunto(struct Circulo v[],int *n, const struct Circulo circulo){
	v[*n] = circulo;
	*n = *n + 1;
}


void VectorDentroFuera(const struct Circulo v[], int n, struct Circulo dentro[], int *util_dentro, struct Circulo fuera[], int *util_fuera, const struct Punto punto){
	int i;
	
	*util_dentro = 0;
	*util_fuera = 0;

	for(i=0;i<n;i++){
		if(CirculoContienePunto(v[i],punto))
			AnyadePunto(dentro,util_dentro,v[i]);
		else
			AnyadePunto(fuera,util_fuera,v[i]);
	}
}

void ImprimePunto(const struct Punto punto){
	printf("%d %d",punto.x,punto.y);
}

void ImprimeVectorCirculos(const struct Circulo v[], int n){
	int i;

	for(i=0;i<n;i++){
		ImprimePunto(v[i].centro);
		printf(" %d\n",v[i].radio);
	}
}



int main(){
	int num_circulos, num_dentro, num_fuera;
	struct Punto punto;
	struct Circulo vector[MAX];
	struct Circulo dentro[MAX];
	struct Circulo fuera[MAX];

	scanf("%d",&num_circulos);
	LeeVectorCirculos(vector,num_circulos);
	LeePunto(&punto);


	VectorDentroFuera(vector,num_circulos,dentro,&num_dentro,fuera,&num_fuera,punto);

	printf("DENTRO\n");
	ImprimeVectorCirculos(dentro,num_dentro);
	printf("FUERA\n");
	ImprimeVectorCirculos(fuera,num_fuera);

	return 0;
}
