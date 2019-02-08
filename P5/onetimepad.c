#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{	
	char mensaje[100], llave[100], cifrado[100], ch;
	int cont = 0;

	FILE *msj = fopen("mensaje.txt","r+");
	FILE *key = fopen("llave.txt","w");
	FILE *cipher = fopen("cifrado.txt","w");

	srand(time(NULL)); // Semilla para numeros aleatorios
	// int test = rand()%255; //Primer disparo del robot
	// printf ("El numero aleatorio de test vale %d\n", test);

	while((ch = fgetc(msj)) != EOF){	
    	// printf("%c", ch);
    	mensaje[cont++]= ch;
	}
	mensaje[cont]='\0';

	// printf("%s\n",mensaje);
	// printf("%d\n",strlen(mensaje));

	for (int i = 0; i < strlen(mensaje)-1; ++i)
	{
		llave[i] = (char)rand()%255;
	}

	printf("%s\n",llave);
	printf("%d\n",strlen(llave));


	
	return 0;
}