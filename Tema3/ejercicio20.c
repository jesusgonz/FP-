#include <stdio.h>

#define MAX 9
#define MIN 1


//// Cometido: imprimir en pantalla un menú
//// Entradas: ninguna
//// Salida: imprime el menú por stdin 

void MostrarMenu(){
	printf("1 Mercurio\n");
	printf("2 Venus\n");
	printf("3 Tierra\n");
	printf("4 Marte\n");
	printf("5 Jupiter\n");
	printf("6 Saturno\n");
	printf("7 Urano\n");
	printf("8 Neptuno\n");
	printf("9 Pluton\n");
}



int main(void){
	int eleccion;
	int distancias[]={58,108,150,228,750,1431,2877,4509,5916};

	

	MostrarMenu();
	do{
		scanf("%d", &eleccion);
	} while((eleccion > MAX) || (eleccion < MIN));

	switch(eleccion){
		case 1:
			printf("%d ",58);
			break;
		case 2:
			printf("%d ",108);
			break;
		case 3:
			printf("%d ",150);
			break;
		case 4:
			printf("%d ",228);
			break;
		case 5:
			printf("%d ",750);
			break;
		case 6:
			printf("%d ",1431);
			break;
		case 7:
			printf("%d ",2877);
			break;
		case 8:
			printf("%d ",4509);
			break;
		case 9:
			printf("%d ",5916); 
			break;
	}

	
	

	return 0;
}
			
	
