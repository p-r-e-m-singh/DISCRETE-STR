#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t a ;
	a = fork();
	if(a<0)
	{
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if(a==0)
	{
		printf("In child process with Process Id :%d \n",getpid());
	}
	else
	{
		wait(NULL); //Remove this wait to make it part b
		printf("In PArent process with process Id :%d \n",getpid());
		
	}
	return 0;
} s
