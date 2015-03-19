#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int pfs_init(void) {
    printk(KERN_ALERT "Hello, world\n");
    return 0;
}

static void pfs_exit(void) {
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(pfs_init);
module_exit(pfs_exit);
