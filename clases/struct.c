#include <stdio.h>

struct x{
	char n;
	int i;
	int o;
};

union y{
	char n;
	int i;
	int o;	
};

int main(int argc, char const *argv[])
{
	struct x estructura;
	union y uniones;

	printf("%d\n",sizeof(struct x));
	printf("%d\n",sizeof(estructura));
	printf("%d\n",sizeof(union y));
	printf("%d\n",sizeof(uniones));
	return 0;
}