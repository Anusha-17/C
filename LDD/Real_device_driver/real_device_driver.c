#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/err.h>

#define mem_size 1024

dev_t dev=0;
static struct class *dev_class;
static struct cdev my_cdev;
uint8_t *kernel_buffer;

/* Function prototype */

static int   __init hello_init(void);
static void  __exit hello_exit(void);
static int my_open(struct inode *inode, struct file *file);
static int my_release(struct inode *inode, struct file *file);
static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off);

static struct file_operations fops=
{
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write,
	.open = my_open,
	.release = my_release,
};

/* This function will be called when we open the device file */

static int my_open(struct inode *inode, struct file *file)
{
	pr_info("Driver open function called...\n");
	return 0;
}

/* This function will be called when we close the device file */
static int my_release(struct inode *inode, struct file *file)
{
	pr_info("Driver release function called...\n");
	return 0;
}

/* This function is called when we read the device file */
static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	
	if(copy_to_user(buf,kernel_buffer,mem_size))
	{
		pr_err("Driver Read : Err! \n");
	}
	pr_info("Data Read : Done !\n");
	return mem_size;
}

/* This function is called when we write the device file */
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{
	if(copy_from_user(kernel_buffer,buf,mem_size))
	{
		pr_err("Driver write : Err! \n");
	}
	pr_info("Data write : Done !\n");
	return len;
}



/* Module init function */

static int __init hello_init(void)
{
	/* Allocating Major number */
	if((alloc_chrdev_region(&dev, 0, 1, "my_dev"))<0)
	{
		pr_err("Cannot allocate major number\n");
		return -1;
	}
	pr_info("Major = %d Minor = %d \n",MAJOR(dev),MINOR(dev));
	
	/* creating cdev structure */
	cdev_init(&my_cdev,&fops);
	
	/* Adding character device to the system */
	if((cdev_add(&my_cdev,dev,1))<0)
	{
		pr_err("Cannot add the device to the system\n");
		goto r_class;
	}
	
	/* creating struct class */
	if(IS_ERR(dev_class = class_create(THIS_MODULE,"my_class")))
	{
		pr_err("Cannot create the struct class\n");
		goto r_class;
	}
	
	/* creating device */
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"my_device")))
	{
		pr_err("Cannot create the device 1\n");
		goto r_device;
	}
	
	/* creating physical memory */
	if((kernel_buffer=kmalloc(mem_size, GFP_KERNEL))==0)
	{
		pr_err("cannot allocate memory in kernel\n");
		goto r_device;
	}
	
	strcpy(kernel_buffer, "Hello World");
	
	pr_info("Device driver insert ... Done!\n");
	return 0;
	
r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}



/* Module exit function */

static void __exit hello_exit(void)
{
	kfree(kernel_buffer);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Device driver removed..\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Cdev fops char driver");
MODULE_VERSION("1.0");

