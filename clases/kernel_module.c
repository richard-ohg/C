#include <linux/module.h>
#include <linux/kernel.h>


int init_module(void)
{
	printk(KERN_INFO "hola Mundo! \n");
	return 0;
}

void cleanup(void){
	printk(KERN_INFO "Goodbye world 1.\n");
}