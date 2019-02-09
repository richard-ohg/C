#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init inicio(void)
{
	printk(KERN_INFO "hola Mundo! \n");
	return 0;
}

static void __exit(void){
	printk(KERN_INFO "Adios Mundo\n");
}

module_init(inicio);
module_exit(fin);