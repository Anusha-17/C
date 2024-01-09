#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Frist driver program");
MODULE_VERSION("1.0");

static int __init hello_world_init(void)
{
	/*printk(KERN_INFO "Welcome to EmbeTronicX\n");
    	printk(KERN_INFO "This is the Simple Module\n");
    	printk(KERN_INFO "Kernel Module Inserted Successfully...\n");*/
    	
    	printk(KERN_INFO "Welcome to Device Drivers\n");
    	printk(KERN_INFO "Kernel module inserted\n");
	return 0;
}

void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Kernel module removed\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
