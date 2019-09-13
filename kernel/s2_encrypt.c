#include <linux/kernel.h>
#include <linux/errno.h>
//#include <stdlib.h>
//#include <iostream.h>
//#include <stdio.h>

int sys_s2_encrypt( char *s1, int key){
	if((key >=1) && (key <=5)){
		while(*s1 != '\0'){
			*s1 = *s1 + key;
			char temp;
			temp = *s1++;
			printk("%c", temp);
		}
		printk("\n");
		return (0);
	}
	else{
		return(EINVAL);
	}


}

//int main(int argc, char *argvc[]){
//	char s[100] = "garvit";
//	int enc_ret;
//	printf("%s\n", s);
//	enc_ret = sys_s2_encrypt(s, 1);
//	printf("%d", enc_ret);
//	printf("\n");
//	return 0;
//}

