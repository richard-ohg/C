#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char pass_in[50];
	for (int i = 0; i < 3; ++i)
	{
		printf("Ingresa tu password: ");
		scanf("%s",pass_in);
		// fgets(pass_in,50,stdin);
		if (strcmp(pass_in,"hola123,") == 0){
			printf("Contraseña correcta\n");
			break;
		}
		else
			printf("Contraseña incorrecta\n");	
	}
	
	return 0;
}