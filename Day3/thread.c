#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];

void *read_thread(void *args)
{
    while (strncmp("stop", buffer, 4) != 0)
    {
        printf("Enter text: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        sleep(1);
    }
    char message[BUFFER_SIZE];
    printf("Enter Exit message: ");
    fgets(message,BUFFER_SIZE,stdin);
    pthread_exit(&message);
}

void *convert_thread()
{
    int i;
    while (strncmp("stop", buffer, 4) != 0)
    {
        sleep(1);
        printf("Converted text: ");
        for (i = 0; i < strlen(buffer); i++)
            printf("%c", toupper(buffer[i]));
    }
    pthread_exit("Convert_thread exist successfull");
}

int main()
{
    int result;
    pthread_t rthread, cthread;
    void *thread_result;
    printf("Enter Text, the program will convert it into upper case,\nTo Stop enter'stop'\n");
    pthread_create(&rthread, NULL, read_thread, NULL);
    pthread_create(&cthread, NULL, convert_thread, NULL);
    pthread_join(rthread, &thread_result);
    printf("read_thread joined,%s\n", thread_result);
    pthread_join(cthread, &thread_result);
    printf("convert_thread joined %s \n", (char *)thread_result);
    return 0;
}

/*
OUTPUT:
Enter Text, the program will convert it into upper case,
To Stop enter'stop'
Enter text: hello
Converted text: Converted text: Converted text: Converted text: Converted text: Converted text: Converted text: Converted text: HELLO
Enter text: Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
Converted text: HELLO
sConverted text: HELLO
top
Converted text: STOP
read_thread joined,read_thread exit successfull
convert_thread joined Convert_thread exist successfull 
*/