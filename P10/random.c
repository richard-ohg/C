#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int fd;
	char *archivo = "/dev/random";
	size_t numero;
	fd = open(archivo,O_RDONLY);

	read(fd,&numero,sizeof(int));
	printf("%u",numero);

	close(fd);
	return 0;
}