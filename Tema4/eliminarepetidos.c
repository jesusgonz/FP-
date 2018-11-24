#include <stdio.h>

#define MAX 100

int RepetidoP(const int v[], int util, int indice){  
	int repetido = 0;
	int i;

	
		for(i=0;i<indice && !repetido;i++){
			if(v[indice] == v[i])
				repetido = 1;
		}

		for(i=indice+1;i<util && !repetido;i++){
			if(v[indice] == v[i])
				repetido = 1;
		}
	
		return repetido;
				
}


void EliminarPosicion(int v[], int *util, int indice){			/// Se realiza un paso por referencia de útil para actualizar su valor(util--) al eliminar una posición del vector
	int i;
	int v_util = *util; 			/// Evita trabajar con el puntero

	for(i = indice;i<(v_util-1);i++){
		v[i] = v[i+1];
	}

	*util=*util-1;
}

void EliminaRepetidos(int v[], int *util){		/// Recorre el vector, eliminando cada repetición del elemento i-ésimo y actualizando el valor de útil 
	int i, j;

	for(i=0;i<(*util);i++){
		j = i;
		while(RepetidoP(v,*util,j)){
			EliminarPosicion(v,util,j);
		}
	}
	
}

void ImprimeVectorEntero(const int v[], int util){
	int i;

	for(i=0;i<util;i++)
		printf("%d \n",v[i]);
}

int main(){
	int v[MAX] = {0,0,0,0,5};
	int util = 5; 

	EliminaRepetidos(v,&util);
	ImprimeVectorEntero(v,util);

	return 0;
}
						

		
		
