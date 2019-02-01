#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char aux[strlen(argv[1])];
	int entero;
	for (int i = 0; i < strlen(argv[1]); ++i)
	{
		entero = ((((int)argv[1][i]-97)+13)%26)+97;
		// printf("%d\n",entero);
		aux[i]= (char)entero;
		// printf("%c\n",argv[1][i]);
	}
	printf("%s\n",aux);
	return 0;
}