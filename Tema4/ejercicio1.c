#define DIM_VECTOR 12
#define DIM_VALOR 6


int main(void){
	int vector[DIM_VECTOR];
	char letras[]= {'H','o','l','a'};				//////////// El vector se inicializa automaticamente a 4 
	double valor[DIM_VALOR];
	int p[] = {0};
	int i;

	vector[0]=1;							//////////// Inicialización de vector
	for(i=1;i<DIM_VECTOR;i++)
		vector[i]=vector[i-1]+3;




	for(i=0;i<DIM_VALOR;i++)
		valor[i] = 1/(i+1);

}
	
