#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>


static struct class *firstdrv_class;  //分配一个类
static struct device    *firstdrv_class_dev;
volatile unsigned long *gpfcon = NULL;
volatile unsigned long *gpfdat = NULL;

static int first_drv_open(struct inode *inode, struct file *file)
{
    //printk("first_drv_open\n");
    /* 配置GPF4,5,6为输出 */
    *gpfcon &= ~((0x3<<(4*2)) | (0x3<<(5*2)) | (0x3<<(6*2)));
    *gpfcon |= ((0x1<<(4*2)) | (0x1<<(5*2)) | (0x1<<(6*2)));
    return 0;
}

static ssize_t first_drv_write(struct file *file, const char __user *buf, size_t count, loff_t * ppos)
{
    //char val[100] = "excuseme";
    int val = 100; 
   //printk("first_drv_write\n");
    int ret = copy_from_user(&val, buf, count); //    copy_to_user();
    printk("ret = %d\n", ret);

    printk("valxx = %d\n", val);  // use dmsg to watch
    printk("count = %d\n", count);  // use dmsg to watch
    switch (val) {
        case 1: // open 
            *gpfdat &= ~(1<<4);
            break;
        case 2:
            *gpfdat &= ~(1<<5);
            break;
        case 3:
            *gpfdat &= ~(1<<6);
            break;
        case 4:
            *gpfdat |= (1<<4);
            break;
        case 5:
            *gpfdat |= (1<<5);
            break;
        case 6:
            *gpfdat |= (1<<6);
            break;
    }
    return 0;
}

static struct file_operations first_drv_fops = {
    .owner  =   THIS_MODULE,    /* 这是一个宏，推向编译模块时自动创建的__this_module变量 */
    .open   =   first_drv_open,     
    .write    =    first_drv_write,       
};

int major;

static int first_drv_init(void)
{
    major = register_chrdev(0, "first_drv", &first_drv_fops); // 注册, 告诉内核
                        //参数为0是系统随机分配主设备号
    firstdrv_class = class_create(THIS_MODULE, "first_drv");
    firstdrv_class_dev = device_create(firstdrv_class, NULL, MKDEV(major, 0), NULL, "xyz"); /* /dev/xyz */
    //功能是让系统自动生成设备节点
    gpfcon = (volatile unsigned long *)ioremap(0x56000050, 16);
    gpfdat = gpfcon + 1;
    return 0;
}

static void first_drv_exit(void)
{
    unregister_chrdev(major, "first_drv"); // 卸载
    device_destroy(firstdrv_class_dev, MKDEV(major, 0));
    class_destroy(firstdrv_class);
    iounmap(gpfcon);
}

module_init(first_drv_init);
module_exit(first_drv_exit);
MODULE_LICENSE("GPL");//这是一个协议
