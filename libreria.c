#include <stdio.h>

#define MAX 100

struct libro {
	int id;
	int a_pub;
};

void IntercambiaLibros(struct libro *a, struct libro *b){
	struct libro aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void OrdenaLibreria(struct libro libreria[], int n){
	int i, j, min;

	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(libreria[j].a_pub < libreria[min].a_pub){
				min = j;
			} else if(libreria[j].a_pub == libreria[min].a_pub){
				if(libreria[min].id < libreria[j].id)
					min = j;
			}
		}

		IntercambiaLibros(&libreria[min],&libreria[i]);
	}
}


void LeeVectorLibros(struct libro v[], int n){
	int i;

	for(i=0;i<n;i++){
		scanf("%d",&v[i].id);
		scanf("%d",&v[i].a_pub);
	}
}

void ImprimeVectorLibro(const struct libro v[], int n){
	int i;

	for(i=0;i<n;i++){
		printf("%d %d\n",v[i].id,v[i].a_pub);
	}
}

int main(){
	int num_libros;
	struct libro libreria[MAX];

	scanf("%d",&num_libros);
	LeeVectorLibros(libreria,num_libros);

	OrdenaLibreria(libreria,num_libros);

	ImprimeVectorLibro(libreria,num_libros);
	
	return 0;
}

