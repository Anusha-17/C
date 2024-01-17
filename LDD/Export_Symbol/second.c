#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("A sample driver");
MODULE_VERSION("1:0.0");

extern int my_count;
void my_func(void);


static int __init hello_init(void)
{
	printk(KERN_INFO "Hello... this is my second");
	my_func();
	return 0;
}


void __exit hello_exit(void)
{
	printk(KERN_INFO "Exiting my second program");
}

module_init(hello_init);
module_exit(hello_exit);
