#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rot13(char *);

int main(int argc, char const *argv[])
{
	char pass_in[50];
	for (int i = 0; i < 3; ++i)
	{
		printf("Ingresa tu password: ");
		scanf("%s",pass_in);
		if (strcmp(rot13(pass_in),rot13("hola123,")) == 0){
			printf("Contraseña correcta\n");
			break;
		}
		else
			printf("Contraseña incorrecta\n");	
	}
	
	return 0;
}

char* rot13(char *string){
    char *aux = (char*) malloc(strlen(string)*sizeof(char)); 
    for (int i = 0; i < strlen(string); ++i)
    {
        int entero = (int)string[i]+13;
        aux[i]= (char)entero;
    }
    return aux;
}
