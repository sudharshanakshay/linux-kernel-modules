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


**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

Explaination, 
- writing kernel module requires **two** important functions i.e. '**__init**' & '**__exit**'.
	1. '**__init**' function is called when the modules is loaded to the kernel.
	2. '**__exit**' function is called when the module is removed from the kernel. 
- '**printk()**' function in **C** language is similar to '**printf()**', but prints message to the '_kernel log_' .

### Support

To update the [web page](https://github.com/sudharshanakshay/linux-kernel-modules/edit/main/docs/index.md) click [here](https://github.com/sudharshanakshay/linux-kernel-modules/edit/main/docs/index.md)


