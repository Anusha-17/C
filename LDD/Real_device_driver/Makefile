obj-m+= real_device_driver.o
 #obj-m is to build as module
 #obj-y is to build as statically
 
 
# It refer the kernel build scripts from below path and build the driver

KDIR = /lib/modules/$(shell uname -r)/build
 
all:	
	make -C $(KDIR) M=$(shell pwd) modules
clean:
	make -C $(KDIR) M=$(shell pwd) clean
