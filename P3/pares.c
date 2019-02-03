#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// for (int i = 0; i < 20; i++)
	// 	printf("%d %s\n",i, (i&1 == 1) ? "impar":"par");
	printf("El número: %d es %s\n",atoi(argv[1]), (atoi(argv[1])&1 == 1) ? "impar":"par" );
	return 0;
}