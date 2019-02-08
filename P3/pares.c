#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc < 2){
		printf("Ingresa el numero limite para imprimir los pares\n");
		exit(1);
	}

	for (int i = 0; i < atoi(argv[1]); i++)
		i&1 ? : printf("%d ",i);

	return 0;
}