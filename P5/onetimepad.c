#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void leer_mensaje(FILE *archivo_msj,char *arreglo_msj);
void generar_llave(FILE *archivo_llave, char *mensaje, char *arreglo_llave, int longitud_msj);
void cifrar(FILE *archivo_cifrado, char *mensaje, int longitud_msj, char *llave, char *arreglo_cifrado);
// void descifrar(FILE *archivo_descifrado, char *cifrado, char *llave, char *arreglo_descifrado);

int main(int argc, char const *argv[])
{	
	char mensaje[100], llave[100], cifrado[100], descifrado[100];

	// Semilla para números aleatorios
	srand(time(NULL));

	// Apertura de archivos
	FILE *f_msj = fopen("mensaje.txt","r+");
	FILE *f_key = fopen("llave.txt","w");
	FILE *f_cipher = fopen("cifrado.txt","w");

	// Comprobación del archivo
	if (f_msj == NULL) {
		printf("El archivo del mensaje no existe\n");
		exit(1);
	}
	
	// Lectura de archivo del mensaje
	leer_mensaje(f_msj, mensaje);

	// Prueba de lectura de mensaje
	printf("mensaje: %s\n",mensaje);
	printf("longitud mensaje: %d\n",strlen(mensaje));

	// Generacion de la llave con numeros aleatorios de ascii y escritura en archivo
	generar_llave(f_key, mensaje, llave, strlen(mensaje));
	
	// Comprobación de generación de llave
	printf("llave: %s\n", llave);
	printf("longitud llave: %d\n", strlen(llave));

	// Ciframos el mensaje
	cifrar(f_cipher, mensaje, strlen(mensaje), llave, cifrado);

	// Comprobación de cifrado
	printf("cifrado: %s\n",cifrado);
	printf("longitud cifrado: %d\n",strlen(cifrado));
	
	// Cerramos archivos
	fclose(f_msj);
	fclose(f_key);
	fclose(f_cipher);

	return 0;
}

// Función para leer el mensaje de un archivo y lo guarda en un arreglo
void leer_mensaje(FILE *archivo_msj, char *arreglo_msj){
	char ch;
	int cont=0;
	// Lectura de archivo del mensaje
	while((ch = fgetc(archivo_msj)) != EOF){	
    	// printf("%c", ch);
    	arreglo_msj[cont++]= ch;
	}
	arreglo_msj[cont]='\0';
}

// Función para generar la llave mediante números aleatorios, se guarda en un arreglo
void generar_llave(FILE *archivo_llave, char *mensaje, char *arreglo_llave, int longitud_msj){
	char ch;
	int cont = 0;
	while(cont < longitud_msj){
		ch = '0' + rand()%(('z'-'0')+1);
		// printf("%d ",ch);
		arreglo_llave[cont] = ch;
		fputc(arreglo_llave[cont],archivo_llave);
		cont++;
	}
	arreglo_llave[strlen(mensaje)] = '\0';
}

// Función para generar el cifrado mediante una xor entre el mensaje y la llave 
void cifrar(FILE *archivo_cifrado, char *mensaje, int longitud_msj, char *llave, char *arreglo_cifrado){
	for(int i = 0; i < strlen(mensaje); i++)
	{
		arreglo_cifrado[i] = mensaje[i] ^ llave[i];
		fputc(arreglo_cifrado[i],archivo_cifrado);
	}
	arreglo_cifrado[strlen(mensaje)] = '\0';
}