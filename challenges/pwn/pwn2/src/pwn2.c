// gcc -o pwn pwn2.c -std=c99 -g -fno-stack-protector -Wl,-z,execstack
// ASLR disabled

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);

    char buffer[64];
    printf("Whats your name?: ");
    gets(buffer);
    printf("Hello, %s\n", buffer);

    return 0;
}