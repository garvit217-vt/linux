#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/errno.h>
//#include <stdlib.h>
//#include <iostream.h>
//#include <stdio.h>

//int __sys_s2_encrypt(char *s1, int key){
//	printk("Inside\n");
//	char kernel_str[100];
//	long int cp_user;
//	//cp_user = copy_from_user(kernel_str, s1, 100);
//	printk("string: %s",s1);
//	printk("\n");
//	printk("key: %d", key);
//	printk("\n");
//	/*
//	if((key >=1) && (key <=5)){
//		while(*s1 != '\0'){
//			*s1 = *s1 + key;
//			char temp;
//			temp = *s1++;
//			printk("%c", temp);
//		}
//		printk("\n");
//		return (0);
//	}
//	else{*/
//		return(EINVAL);
//	//}
//
//
//}

//SYSCALL_DEFINE3(s2_encrypt, unsigned int, char*, s, int, key){
SYSCALL_DEFINE2(s2_encrypt, char *, s1, int, key)
{
	//printk(KERN_DEBUG "Inside\n");
        char kernel_str[100];
        long int cp_user;
        cp_user = strncpy_from_user(kernel_str, s1, 100);
	char *s = kernel_str;
        //printk(KERN_DEBUG "string: %s",kernel_str);
        //printk("\n");
        //printk(KERN_DEBUG "key: %d", key);
        //printk("\n");
	if((key >=1) && (key <=5)){
              	while(*s != '\0'){
                      	*s = *s + key;
                      	char next_char;
                      	next_char = *s++;
			//kernel_str = kernel_str+1;
                	//printk("%c", next_char);
              	}
		printk("Encrypted_string: %s", kernel_str);
              	printk("\n");
        	return (0);
      	}
	else{
        	return(EINVAL);
	}
	return 0;
}




//	printk("inside sys_define, key: %d\n", key);
//	return sys_s2_encrypt(s1, key);
//	//printk("Inside\n");
//	//printk("%c", *s1);
//        //printk("\n");
//        //printk("%d", key);
//        //printk("\n");
//        //char temp;
//        //if((key >=1) && (key <=5)){
//        //        while(*s1 != '\0'){
//        //                *s1 = *s1 + key;
//        //                temp = *s1++;
//        //                printk("%c", temp);
//        //        }
//        //        printk("\n");
//        //        return (0);
//        //}
//        //else{
//        //        return(EINVAL);
//        //}
//}
//
////int main(int argc, char *argvc[]){
////	char s[100] = "garvit";
////	int enc_ret;
////	printf("%s\n", s);
////	enc_ret = sys_s2_encrypt(s, 1);
////	printf("%d", enc_ret);
////	printf("\n");
////	return 0;
////}
//
