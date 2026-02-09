#include <stdio.h>
#include <unistd.h>
int main(){
	printf("Hello\n");
	fork();
	printf("Hello from fork\n");
	fork();
	printf("hello from deep fork\n");
	return 0;
}
