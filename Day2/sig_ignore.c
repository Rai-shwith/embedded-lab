#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
signal(SIGINT,SIG_IGN);
while(1){
	printf("ID: %d\n",getpid());
	sleep(1);
}
return 0;
}
