/**

* @file hello.c
* @author Sudharshan Akshay
* @date 3-jun-2022
* @version 1
* @brif module prints 'hello world'
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Sudharshan Akshay")

MODULE_DESPRIPTION("A Simple Hello world LKM ");

MODULE_VERSION("1");

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
