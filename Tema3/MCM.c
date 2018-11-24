#include <stdio.h>

int MCM(int a, int b){
	int mayor, menor, i; 		
	(a >= b) ? ((mayor=a) && (menor=b)):((menor=a)&&(mayor=b));

	for(i=mayor;i<(mayor*menor);i++){
		if((i%mayor==0)&&(i%menor==0))
			return i;
	}

	return mayor*menor;
}

int main(){
	int a,b, mcm;

	scanf("%d",&a);
	scanf("%d",&b);
	mcm = MCM(a,b);

	printf("\nEl mcm de %d y %d es %d",a,b,mcm);

	return 0;
}
	


