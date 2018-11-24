#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

void Encripta(char *cad){
	int i;

	for(i=0;i<strlen(cad);i++){
		cad[i] += 5;
	}
}

void Desencripta(char *cad){
	int i;

	for(i=0;i<strlen(cad);i++){
		cad[i] -= 5;
	}
}

void LeeCadena(char *cad){
	do{
		gets(cad);
	}while(cad[0] == '\0');
}

int main(void){
	char cad[N];

	LeeCadena(cad);

	Encripta(cad);
	printf("%s\n",cad);

	Desencripta(cad);
	printf("%s\n",cad);

	return 0;
}
