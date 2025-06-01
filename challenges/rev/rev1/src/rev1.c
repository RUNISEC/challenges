// gcc rev1.c -o rev

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    // The program is designed to read a string from the user, reverse it, and print the reversed string.
    char passwd[24] = "SuperSecretPassword123";
    char str[64];

    printf("Enter the password to get the flag!: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character from the input

    if (strcmp(str, passwd) == 0)
    {
        printf("Correct password! Here is the flag:\n");
        system("cat flag.txt");
    }
    else
    {
        printf("Incorrect password! Exiting!\n");
    }

    return 0;
}