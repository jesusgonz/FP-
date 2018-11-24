#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int ConvierteABinario(int num){
	int binario = 0;
	int i = 0;
	int resto;

	while(num > 0){
		resto = num % 2;
		num /= 2;
		binario += resto * pow(10,i);
		i++;
	}

	return binario;
}

void InvierteCadena(char *cad){
	int i,j;
	char c;

	for(i=0,j=strlen(cad)-1;i<j;i++,j--){
		c = cad[i];
		cad[i] = cad[j];
		cad[j] = c;
	}
}
	

char* ConvierteABinarioDinamico(int num){
	if (num > 0){
		num = ConvierteABinario(num);
		int longitud_num = 2;
		char *v = (char*)malloc(sizeof(char)*longitud_num);
		int i = 0;

		while(num != 0){
			v[i] = (num % 10) + '0';
			num /= 10;
			i++;
			longitud_num++;
			v = (char*)realloc(v,sizeof(char)*longitud_num);
		}

		v[i+1] = '\0';

		InvierteCadena(v);
		return v;
	} else
		return NULL;
}

char* ConvierteABinarioEstatico(int num){
	if (num > 0){
		static char v[MAX];
		int i = 0;
		num = ConvierteABinario(num);

		while(num != 0){
			v[i] = (num % 10) + '0';
			num /= 10;
			i++;
		}

		v[i+1] = '\0';
		InvierteCadena(v);
		return v;
	} else
		return NULL;
}

int main(void){
	int num;
	char *cad_dyn;
	char *cad_static;

	scanf("%d",&num);

	cad_dyn = ConvierteABinarioDinamico(num);
	cad_static = ConvierteABinarioEstatico(num);

	printf("DINAMICO: %s\n",cad_dyn);
	printf("ESTATICO: %s\n",cad_static);

	free(cad_dyn);

	return 0;
}
