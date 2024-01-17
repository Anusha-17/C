#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Allocating Major and Minor no statically");
MODULE_VERSION("5.0");

dev_t dev=MKDEV(235,0);  //creating the dev with our custom major and minor number

static int __init hello_init(void)
{
	register_chrdev_region(dev, 1, "static_dev");
	printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev),MINOR(dev));
	printk(KERN_INFO "Kernel module inserted successfully...\n");
	return 0;
}

void __exit hello_exit(void)
{
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO " Kernel module removed successfully..\n");
}

module_init(hello_init);
module_exit(hello_exit);
