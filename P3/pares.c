#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 20; i++)
		printf("%d %s\n",i, (i&1 == 1) ? "impar":"par");
		// printf("%d\n", 11&1);
	return 0;
}