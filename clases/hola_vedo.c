#define FORMAT_STRING "%s"
#include <stdio.h>

char *msg = "Hola, Vedo\n";

int main(int argc, char const *argv[])
{
	// char *msg[] = {"Hola, Vedo\n"};
	printf(FORMAT_STRING,msg);
	if (argc > 1)
		printf("%s\n",*(argv+1));

	int i = 0;
	for (; i < 5;)
	{
		printf("hola\n");
		i++;
	}



	return 0;
}
