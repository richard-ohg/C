obj-m:=kernel_module2.c
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean:
	rm -rf *.o *.ko *.symvers *.mod.* *.order 
