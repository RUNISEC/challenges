// gcc -o pwn pwn2.c -std=c99 -g -fno-stack-protector -Wl,-z,execstack

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);

    char greeting[64] = "Hello, ";
    printf("Whats your name?: ");
    gets(greeting + 7);
    printf(greeting);

    char from[64];
    printf("\nWhere are you from?: ");
    gets(from);
    printf("Ive never met somebody from %s before!\n", from);

    return 0;
}