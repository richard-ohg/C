#include <stdio.h>
#include <stdlib.h>

int factorial(int numero);

int main(int argc, char const *argv[])
{
	printf("%d\n", factorial(atoi(*(argv+1))));
	return 0;
}

int factorial(int numero){
	if (numero==1)
		return 1;
	else
		return numero*factorial(numero-1);
}
