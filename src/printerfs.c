#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

int printerfs_fill_sb(struct super_block *sb, void *data, int silent) {
    /* https://www.kernel.org/doc/Documentation/filesystems/vfs.txt
     * (*data) is going to be arbitrary mount options, usually ASCII string.
     * We can use this to pass in an initial IP for this node to attempt to
     * connect to to get information about the cluster.
     *
     * In addition, here we can spin up a kernel thread to handle any incoming
     * connections. See the following for details on kernel threads:
     * https://www.kernel.org/doc/htmldocs/device-drivers/API-kthread-run.html
     */
    return 0;
}

static struct dentry *mount_pfs(struct file_system_type *fs_type, int flags,
        const char *dev_name, void *data) {
    struct dentry *ret = mount_bdev(fs_type, flags, dev_name, data,
            printerfs_fill_sb);

    if (unlikely(IS_ERR(ret))) {
        printk(KERN_ERR "Error mounting PrinterFS.\n");
    } else {
        printk(KERN_INFO "PrinterFS is succesfully mounted on [%s].\n", dev_name);
    }

    return ret;
}

static void kill_pfs_superblock(struct super_block *s) {
    /* Dummy function for now. */
    return;
}

struct file_system_type pfs_fs_type = {
    .owner   = THIS_MODULE,
    .name    = "printerfs",
    .mount   = mount_pfs,
    .kill_sb = kill_pfs_superblock
};

static int pfs_init(void) {
    int ret = register_filesystem(&pfs_fs_type);
    if (ret == 0) {
        printk("Registered PrinterFS.\n");
    } else {
        printk("Could not register PrinterFS.\n");
    }
    return ret;
}

static void pfs_exit(void) {
    int ret = unregister_filesystem(&pfs_fs_type);
    if (ret == 0) {
        printk("Unregistered PrinterFS.\n");
    } else {
        printk("Could not unregister PrinterFS.\n");
    }
}

module_init(pfs_init);
module_exit(pfs_exit);
