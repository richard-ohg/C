#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char pass[50];
	for (int i = 0; i < 3; ++i)
	{
		printf("Ingresa tu password: ");
		scanf("%s",pass);
		if (strcmp(pass,"hola123,") == 0){
			printf("Contraseña correcta\n");
			break;
		}
		else if (i==2)
			exit(1);
		else
			printf("Contraseña incorrecta\n");	
	}
	
	return 0;
}