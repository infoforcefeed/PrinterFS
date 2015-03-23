# PrinterFS Detailed Overview

PrinterFS is a distributed filesystem, which supports almost no features. The
goal is to just have way to turn small disks into one large disk.

The `inode` space is global, and shared among all nodes.

Questions:

* How does mkfs work? Do we need to do anything?

## Top-level Operations

`struct file_system_type` should have:

* mount
* kill_sb

In addition to all the rest of the stuff that it needs to have, like `owner` and
`name` or whatever.

### mount

* Specify mount options to join existing cluster

### kill_sb

`TODO`.

## FS Operations

`struct file_operations` should have:

* read
* write
* open?

### write

open() should just work



### read

Read

## Inode Operations

`struct inode_operations` should have:

* create
* mkdir
* rmdir
