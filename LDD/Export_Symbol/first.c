#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("A sample driver");
MODULE_VERSION("1:0.0");

int my_count=0;
void my_func(void)
{
	printk(KERN_INFO "Shared function been called!!!\n");
	my_count++;
}

EXPORT_SYMBOL(my_func);
EXPORT_SYMBOL(my_count);

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello... this is my first");
	return 0;
}


void __exit hello_exit(void)
{
	printk(KERN_INFO "Exiting my program");
}

module_init(hello_init);
module_exit(hello_exit);
