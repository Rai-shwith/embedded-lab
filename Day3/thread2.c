#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];

void *read_name(void *name)
{
    printf("Name Process ID is %ld\n", pthread_self());
    printf("%s", (char *)name);
    char inp[BUFFER_SIZE];
    printf("Enter input: ");
    fgets(inp, BUFFER_SIZE, stdin);
    pthread_exit(&inp);
}

void *read_usn(void *usn)
{
    sleep(5);
    printf("USN Process ID is %ld\n", pthread_self());
    printf("%s", (char *)usn);
    char inp[BUFFER_SIZE];
    printf("Enter college name: ");
    fgets(inp, BUFFER_SIZE, stdin);
    pthread_exit(&inp);
}

int main()
{
    pthread_t name_t, usn_t;
    void *res_name, *res_usn;
    char name[100], usn[20];
    printf("Enter name: ");
    fgets(name, 100, stdin);
    printf("Enter USN: ");
    fgets(usn, 20, stdin);
    pthread_create(&name_t, NULL, read_name, &name);
    pthread_create(&usn_t, NULL, read_usn, &usn);
    pthread_join(name_t, &res_name);
    printf("Name Thread Joined. Message: %s", (char *)res_name);
    pthread_join(usn_t, &res_usn);
    printf("USN Thread Joined. Message: %s", (char *)res_usn);
    return 0;
}
/*
OUTPUT:
Enter name: Ashwith
Enter USN: 1MS23EC029
Name Process ID is 126788113254080
Ashwith
Enter input: Hello
Name Thread Joined. Message: Hello
USN Process ID is 126788104861376
1MS23EC029
Enter college name: MSRIT
USN Thread Joined. Message: MSRIT
*/