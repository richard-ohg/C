#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *cadena = "ricardo";
	char *aux = &cadena[strlen(cadena)-1];

	for (int i = 0; i < strlen(cadena); ++i)
	{
		printf("%c\n",*(aux-i));
	}

	return 0;
}

