#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct instructor{
	char nombre[50];
	char curso[10];
	int edad;
	bool carisma;
};

struct instructor ins(struct instructor i);

int main(int argc, char const *argv[])
{
	struct instructor i;

	i = ins(i);
	
	printf("%s\n",i.nombre);
	printf("%s\n",i.curso);
	printf("%d\n",i.edad);
	printf("%d\n",i.carisma);
	
	return 0;
}

struct instructor ins(struct instructor i){
	// i.nombre = "fernando";
	strcpy(i.nombre,"Fernando");
	// i.curso = "C";
	strcpy(i.curso,"C");
	i.edad = 28;
	i.carisma = NULL;
	// i.carisma[0] = '\0';
	// memset(i.carisma,NULL,1);

	return i;
}
