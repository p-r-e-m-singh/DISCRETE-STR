#include<stdlib.h>
#include<stdio.h>
int main()
{
	printf("\n the Kernel  Version is :\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\n The CPU info :\n");
	system("cat /proc/cpuinfo\n");
	printf("\n");
	return 0;
}

