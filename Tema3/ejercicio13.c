#include <stdio.h>
#include <math.h>

long int factorial(long int f){
	if(f==0)
		return 1;
	return(f*factorial(f-1));
}
	

double seno(int n, double x){
	double s = 0;
	int i;

	for(i=0;i!=n;i++)
		s += pow(-1,i)*pow(x,2*i+1)/factorial(2*i+1);
	
	return s;
}


