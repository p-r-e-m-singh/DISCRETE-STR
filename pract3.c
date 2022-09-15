#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int a;
	printf("\n Kernel Version : ");
	system("cat /proc/sys/kernel/osrelease");
	printf("\nConfigured free and used memory:\n");
	system("cat /proc/meminfo | awk 'NR==1,NR ==1000 {print}'");
	return 0;
}

