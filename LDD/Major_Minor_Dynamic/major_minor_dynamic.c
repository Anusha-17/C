#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Allocating Major and Minor no dynamically");
MODULE_VERSION("5.0");

dev_t dev=0;

static int __init hello_init(void)
{
	if((alloc_chrdev_region(&dev, 0, 1, "dynamic_dev"))<0)
	{
		printk(KERN_INFO "Cannot allocate major and minor number for device 1\n");
		return -1;
	}
	printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
	printk(KERN_INFO "Kernel module inserted successfully..\n");
	return 0;
}

void __exit hello_exit(void)
{
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "Kernel module removed successfully..\n");
}

module_init(hello_init);
module_exit(hello_exit);
