#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/ioctl.h>
#include<linux/err.h>
#include<linux/fcntl.h>
#include<linux/export.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

int32_t value=0;

dev_t dev=0;
static struct class *dev_class;
static struct cdev my_cdev;

/* Function Prototypes */

static int     __init hello_init(void);
static void    __exit hello_exit(void);
static int     my_open(struct inode *inode,struct file *file);
static int     my_release(struct inode *inode,struct file *file);
static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off);
static long    my_ioctl(struct file *file, unsigned int cmd, unsigned long arg);


/* File Operations */
static struct file_operations fops=
{
	.owner         = THIS_MODULE,
	.read          = my_read,
	.write         = my_write,
	.open          = my_open,
	.unlocked_ioctl= my_ioctl,
	.release       = my_release,
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
	
	pr_info("Read Function..\n");
	return 0;
}

/* This function is called when we write the device file */
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{
	pr_info("Write Function..\n");
	return len;
}

/* This function will be called when we write IOCTL on the Device file */

static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	switch(cmd)
	{
		case WR_VALUE: if(copy_from_user(&value, (int32_t*) arg, sizeof(value)))
				{
					pr_err("Data write : Err! \n");
				}
				pr_info("Value = %d\n",value);
				break;
		case RD_VALUE: if(copy_to_user((int32_t*)arg, &value, sizeof(value)))
				{
					pr_err("Data Read : Err! \n");
				}
				break;
		default : pr_info("Invalid\n");
		  	  break;
	}
	return 0;
}
	
/* Module Init Function */

static int __init hello_init(void)
{
	/* Allocating major number */
	if((alloc_chrdev_region(&dev,0,1,"my_dev"))<0)
	{
		pr_err("Cannot allocate major number\n");
		return -1;
	}
	pr_info(" Major = %d Minor = %d \n",MAJOR(dev),MINOR(dev));
	
	my_cdev.owner = THIS_MODULE;
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
		pr_err("Cannot create the class\n");
		goto r_class;
	}
	
	/* Creating device */
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"my_device")))
	{
		pr_err("Cannot create the device 1\n");
		goto r_device;
	}
	pr_info("Device Driver Inserted Successfully..\n");
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
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Device Driver Removed successfully..\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("IOCTL");
MODULE_VERSION("1.0");

			



