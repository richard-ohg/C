#include <stdio.h>

int fibonacci(int);

int main(int argc, char const *argv[])
{
	int numeros;
	printf("Ingresa cuantos numeros de la serie de fibonacci quieres: ");
	scanf("%d",&numeros);

	for (int i = 0; i < numeros; i++)
	{
		printf("%d ",fibonacci(i));
	}
	return 0;
}

int fibonacci(int num){
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;		
	else
		return fibonacci(num-1) + fibonacci(num-2);
}
