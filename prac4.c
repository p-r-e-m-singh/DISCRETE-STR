#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
int main(int argc,char *argv[3]){
	int i;
	struct stat buffer;
	struct tm  dt;
	printf("Give file name: ");
	for(i=1;i<argc;i++){
		if(stat(argv[i],&buffer)<0)
		printf("Error in File started");
		else{
			printf("Owner :%d\ngid = %d\n",buffer.st_uid,buffer.st_gid);
			printf("Access Permission= %d\n",buffer.st_mode);
			dt = *(gmtime(&buffer.st_ctime));
			printf("Access time =%d-%d-%d %d:%d;%d\n",dt.tm_mday,dt.tm_mon,dt.tm_year+1900,dt.tm_hour,dt.tm_min,dt.tm_sec);
		}
	}
	return 0;
}
