#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>


int main(int argc, char const *argv[])
{
	char *archivo = "/dev/input/event4";
	struct input_event ev;
	int fd = open(archivo,O_RDONLY);

	int teclas[] = {KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_0,KEY_Q,KEY_W,KEY_E,KEY_R,KEY_T,KEY_Y,KEY_U,KEY_I,KEY_O,KEY_P,KEY_A,KEY_S,KEY_D,KEY_F,KEY_G,KEY_H,KEY_J,KEY_K,KEY_L,KEY_Z,KEY_X,KEY_C,KEY_V,KEY_B,KEY_N,KEY_M};

	char significado[] = {'1','2','3','4','5','6','7','8','9','0','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};

	if (fd == -1)
	{
		printf("No se puede abrir el archivo\n");
		exit(1);
	}

	while(ev.code != KEY_SPACE){
		// sleep(1);
		read(fd, &ev, sizeof(ev));
		if (ev.type == 1)
		{
			for (int i = 0; i < sizeof(teclas)/sizeof(teclas[0]); i++)
			{
				if (ev.code == teclas[i])
				{
					// sleep(0.01);
					printf("%c\n",significado[i]);
					// printf("%c ",significado[i-1]);
					// printf("%c\t",significado[i-1]);
					break;
				}
			}
			// sleep(2);
		}
		// sleep(0.5);
	}
	return 0;
}