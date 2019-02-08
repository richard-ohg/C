#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int fd;
	char *archivo = "/tmp/archivo\0";

	fd = open(archivo,O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);

	write(fd,"hola123.,\n",10);

	close(fd);
	return 0;
}