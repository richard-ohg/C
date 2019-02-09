#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// Para compilar -> gcc hasheo_md5.c -lcrypto -lm
// Para ejecutar -> ./a.out cadena

char *md5(const char*);

int main(int argc, char **argv) {
    char *output = md5(argv[1]);
    printf("El hash es: %s\n", output);
    free(output);
    return 0;
}

// Función para crear md5, recibe  la cadena a cifrar
char *md5(const char *str) {
    int n;
    MD5_CTX c;
    // struct MD5Context c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    // Funciones para generar hash md5 de una cadena
	MD5_Init(&c);
    MD5_Update(&c, str, strlen(str));
    MD5_Final(digest, &c);

    // Impresión del hash
    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }
    // Retornamos el apuntador
    return out;
}