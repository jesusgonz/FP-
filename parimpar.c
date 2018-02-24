#include <stdio.h>
#include <string.h>

#define MAX 100

void LeeCadena(char *cad){
	do{
		gets(cad);
	} while(cad[0] == '\0');
}

void EliminaPosicion(char *cad, int pos){
	int i;

	for(i=pos;i<strlen(cad);i++)
		cad[i] = cad[i+1];
}


void EliminaEspacios(char *cad){
	int i;

	i=0;

	while(i<strlen(cad)){
		while(cad[i] == ' ')
			EliminaPosicion(cad,i);

		i++;
	}
}

int EsPalindromo(const char *cad){
	int i;
	int es_palindromo = 1;

	for(i=0;i<strlen(cad)/2 && es_palindromo;i++){
		if(cad[i] != cad[strlen(cad)-1-i])
			es_palindromo = 0;
	}

	return es_palindromo;
}

int EsPar(const char *cad){
	return ((strlen(cad) > 2) && (strlen(cad) % 2 == 0) && (cad[strlen(cad)/2-1] == cad[strlen(cad)/2]));
}

int EsImpar(const char *cad){
	return ((strlen(cad) >= 3) && (strlen(cad) % 2 != 0) && (cad[strlen(cad)/2] == cad[0]));
}

int main(void){
	char cad[MAX];
	const char PALINDROMO[MAX] = "PALINDROMO";
	const char PAR[MAX] = "PAR";
	const char IMPAR[MAX] = "IMPAR";
	const char NINGUNO[MAX] = "NINGUNO";

	LeeCadena(cad);

	EliminaEspacios(cad);

	if(EsPalindromo(cad)){
		printf("%s",PALINDROMO);
	} else if (EsPar(cad)){
		printf("%s",PAR);
	} else if(EsImpar(cad)){
		printf("%s",IMPAR);
	} else
		printf("%s",NINGUNO);

	return 0;
}


	
		
