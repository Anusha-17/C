#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int cb_value=0;



int notify_param(const char *val,const struct kernel_param *kp)
{
	int res=param_set_int(val,kp);
	if(res==0)
	{
		printk(KERN_INFO "Call back function called\n");
		printk(KERN_INFO "New value of cb_value = %d\n",cb_value);
		return 0;
	}
	return -1;
}
const struct kernel_param_ops my_param_ops=
{
	.set=&notify_param,
	.get=&param_get_int,
};

module_param_cb(cb_value, &my_param_ops, &cb_value, S_IWUSR | S_IRUGO);

static int __init hello_init(void)
{
	printk(KERN_INFO "Call back value = %d \n",cb_value);
	return 0;
}

void __exit hello_exit(void)
{
	printk(KERN_INFO "Kernel module removed\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Module param cb");
MODULE_VERSION("3.0");
