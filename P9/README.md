# Práctica 9

Programas:

1. Crear un programa que declare e imprima una estructura que trabaje con la siguiente definicion:
```C
struct instructor ins(struct instructor i){
	i.nombre = "fernando";
	i.curso[0] = "C";
	i.edad = 28;
	i.carisma = NULL;
	
	return i;
}
```