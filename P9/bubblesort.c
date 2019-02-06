#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int array[] = {5,2,7,8,6,3,1,4,10,9};
	int aux;

	for (int i = 0; i < (sizeof(array)/sizeof(array[0])); ++i)
	{
		for (int j = 0; j < (sizeof(array)/sizeof(array[0])-1); ++j)
		{
			if (*(array+j) > *(array+j+1)){
				aux = *(array+j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = aux;

			}
		}
	}

	for (int i = 0; i < (sizeof(array)/sizeof(array[0])); ++i)
	{
		printf("%d ",*(array+i));
	}

	return 0;
}