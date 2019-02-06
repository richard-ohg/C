#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *cadena = "ricardo";
	char *aux = &cadena[strlen(cadena)-1];

	// Recorrer con apuntadores de forma negativa, teniendo el indice 0 en la última posición de la cadena
	for (int i = 0; i < strlen(cadena); ++i)
	{
		printf("%c ",*(aux-i));
	}

	printf("\n");

	// Recorriendo con apuntadores de forma
	for (int i = strlen(cadena)-1 ; i >= 0; --i)
	{
		printf("%c ",*(cadena+i));
	}

	return 0;
}

