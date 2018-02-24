#include <stdio.h>
#include <math.h>

#define MAX 100

struct Punto {
	int x;
	int y;
};

void LeeVectorPuntos(struct Punto v[],int n){
	int i;

	for(i=0;i<n;i++){
		scanf("%d",&v[i].x);
		scanf("%d",&v[i].y);
	}
}

float DistanciaEuclideaR2(struct Punto a, struct Punto b){
	float distancia;

	distancia = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

	return distancia;
}

void IntercambiaPuntos(struct Punto *a, struct Punto *b){
	struct Punto aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

	

void OrdenaDistanciaAPunto(struct Punto v[], int n, int pos){
	if(0 <= pos && pos < n){
		int i, j, min;

		for(i=0;i<n-1;i++){
			min = i;
			for(j=i+1;j<n;j++){
				if(DistanciaEuclideaR2(v[j],v[pos]) < DistanciaEuclideaR2(v[min],v[pos]))
					min = j;
			}

			IntercambiaPuntos(&v[i],&v[min]);
		}
	}
}

void ImprimeVectorPuntos(const struct Punto v[], int n){
	int i;

	for(i=0;i<n;i++){
		printf("%d %d\n",v[i].x,v[i].y);
	}
}

int main(){
	int n, punto;
	struct Punto v[MAX];

	scanf("%d",&n);
	LeeVectorPuntos(v,n);
	scanf("%d",&punto);

	OrdenaDistanciaAPunto(v,n,punto);

	ImprimeVectorPuntos(v,n);

	return 0;
}



	
