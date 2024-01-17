#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Create a device file manually for this driver");
MODULE_VERSION("6.0");

dev_t dev=0;

static int __init hello_init(void)
{
	if((alloc_chrdev_region(&dev,0,1,"char_dev"))<0)
	{
		pr_err("Cannot allocate major no for device\n");
		return -1;
	}
	pr_info("Kernel module inserted successfully..\n");
	return 0;
}

void __exit hello_exit(void)
{
	unregister_chrdev_region(dev,1);
	pr_info("Kernel module inserted successfully..\n");
}

module_init(hello_init);
module_exit(hello_exit);

