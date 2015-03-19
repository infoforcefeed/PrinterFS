MODULE_NAME = PrinterFS

# Add more source files here
SRC     := src/printerfs.c

# Path to target Linux Kernel
KDIR        := /lib/modules/$(shell uname -r)/build # <--- Fill in with path to kernel you're compiling against

$(MODULE_NAME)-objs = $(SRC:.c=.o)

obj-m := $(MODULE_NAME).o

EXTRA_CFLAGS := -I$(PWD)/src -I$(PWD)/include

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
