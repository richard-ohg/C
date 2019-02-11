#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
// #include <stdint.h>
#include <stdio.h>
#include <string.h>

int cifrar_base64(const unsigned char* buffer, size_t length, char** b64text);

int main(int argc, char const *argv[])
{
    char* cadena_cifrada;

    // Cifrar en base64
    cifrar_base64(argv[1], strlen(argv[1]), &cadena_cifrada);
    printf("Cadena cifrada en base64: %s\n", cadena_cifrada);
    
    return 0;
}


// Función para cifrar una cadena en base64
int cifrar_base64(const unsigned char* buffer, size_t length, char** b64text) { 
	BIO *bio, *b64;
	BUF_MEM *bufferPtr;

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
	BIO_write(bio, buffer, length);
	BIO_flush(bio);
	BIO_get_mem_ptr(bio, &bufferPtr);
	BIO_set_close(bio, BIO_NOCLOSE);
	BIO_free_all(bio);

	*b64text=(*bufferPtr).data;

	return (0); //success
}