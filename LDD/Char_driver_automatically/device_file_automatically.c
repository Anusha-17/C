#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/err.h>

dev_t dev=0;
static struct class *dev_class;

static int __init hello_init(void)
{
	if((alloc_chrdev_region(&dev,0,1,"char_dev"))<0)
	{
		pr_err("Cannot aloocate major number for device\n");
		return -1;
	}
	pr_info("Major = %d Minor = %d\n",MAJOR(dev), MINOR(dev));
	
	/*creating sturct class*/
	dev_class = class_create(THIS_MODULE,"char_class");
	if(IS_ERR(dev_class))
	{
		pr_err("Cannot create the struct class for device\n");
		goto r_class;
	}
	
	/*Creating device*/
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"char_device")))
	{
		pr_err("Cannot create the device\n");
		goto r_device;
	}
	pr_info("Kernel module inserted successfully\n");
	return 0;
	
r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit hello_exit(void)
{
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	unregister_chrdev_region(dev,1);
	pr_info("Kernel module removed successfully..\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Creating device file automatically");
MODULE_VERSION("7.0");
