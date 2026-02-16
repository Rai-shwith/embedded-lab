#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void my_handler(int signal){
printf("Problem Encountered %d \n",signal);
exit(0);
}

int main(){
signal(SIGINT,my_handler);
while(1){
	printf("Hello \n");
	sleep(1);
}
return 0;
}
