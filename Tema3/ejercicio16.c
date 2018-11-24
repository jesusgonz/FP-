#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char texto[10000];
	int i, palabras = 1, salto_de_linea = 0;
	int longitud; 


	/// Utilizando gets
	gets(texto);
	longitud = strlen(texto);
	printf("La longitud es %d", longitud);	/// Número total de caracteres 

	for(i=0;i < longitud; i++){
		if(texto[i] == ' ' && texto[i-1] != ' ')
			palabras++;
		if(texto[i] == '\n')
			salto_de_linea++;
	}

	printf("El numero de palabras es %d", palabras);  /// Número de palabras
	printf("El numero de saltos de linea es %d", salto_de_linea);

	return 0;
}


