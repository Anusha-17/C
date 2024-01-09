#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int value,arr_value[4];
char *name;

module_param(value,int, S_IRUSR|S_IWUSR);
module_param(name,charp,S_IRUSR|S_IWUSR);
module_param_array(arr_value, int, NULL, S_IRUSR|S_IWUSR);

static int __init hello_init(void)
{
	int i;
	printk(KERN_INFO "Value = %d \n",value);
	printk(KERN_INFO "Name = %s \n",name);
	for(i=0;i<(sizeof arr_value/sizeof(int));i++)
	{
		printk(KERN_INFO "Array Values[%d] = %d \n",i,arr_value[i]);
	}
	
	printk(KERN_INFO "Kernal module inserted successfully.\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Kernel module removed\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Module Param");
MODULE_VERSION("2.0");
