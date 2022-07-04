## Linux Kernel Modules
	

Tutorial to insert & remove a Loadable kernel module [LKM].

### Writing a kernel module

Create directory '_linux-kernel-module_'

```markdown

$ mkdir linux-kernel-modules
$ cd /linux-kernel-modules

```
Create a file '_hello.c_'

```markdown
$ touch hello.c
```
Write module program in _'hello.c'_ file.

```markdown

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int __init print_hello(void){
	printk(KERN_INFO "Loading hello module...\n");
	printk(KERN_INFO "hello world\n");
	return 0;
}

static void __exit exit_hello(void){
	printk(KERN_INFO "bye bye kernel !\n");
}

module_init(print_hello);
module_exit(exit_hello);
```

Explaination, 
- writing kernel module requires **two** important functions i.e. '**__init**' & '**__exit**'.
	1. '**__init**' function is called when the modules is loaded to the kernel.
	2. '**__exit**' function is called when the module is removed from the kernel. 
- '**printk()**' function in **C** language is similar to '**printf()**', but prints message to the '_kernel log_' .

### Compiling kernel module

- we are using 'make' program to compile our kernel module.
- we need to create a file named '_Makefile_' 

```markdown
$ touch Makefile
```
- with following set of commands

```markdown
obj-m += hello.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
```

- Now compile our kernel module by executing '_make_' .

```markdown
$ make
```

### Load the module to kernel.

- once the '_make_' is successful, '_hello.ko_' file is create.
- '_.ko_' is the kernel object.
- insert this '_.ko_' object to the kernel by,

```markdown
$ sudo insmod hello.ko
```

### Display kernel log

```markdown
$ dmesg
```

### Unload or remove kernel module we inserted,

```markdown
$ sudo rmmod hello
```

- To display again _kernel log_

```markdown
$ dmesg
```

### Support

To update the web page click [here](https://github.com/sudharshanakshay/linux-kernel-modules/edit/main/docs/index.md)
