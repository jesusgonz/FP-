#include <stdio.h>
#include <math.h>


int SumaKCifras(int n1, int n2, int k){
	n1 = (unsigned int)n1;
	n2 = (unsigned int)n2;
	int i = 0;
	int num_1=0, num_2=0;

	while(n1 > 0 && i < k){
		num_1 += (n1 % 10)*pow(10,i);
		n1 /= 10;
		i++;
	}

	i = 0;

	while(n2 > 0 && i < k){
		num_2 += (n2 % 10)*pow(10,i);
		n2 /= 10;
		i++;
	}

	return (num_1 + num_2);
}

int main(void){
	int num_1, num_2, suma;
	int k;

	scanf("%d",&num_1);
	scanf("%d",&num_2);
	scanf("%d",&k);

	
	suma = SumaKCifras(num_1,num_2,k);

	printf("La suma es %d",suma);

	return 0;
}

		
