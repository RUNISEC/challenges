// gcc rev1.c -o rev

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    // The program is designed to read a string from the user, reverse it, and print the reversed string.
    char passwd[32] = "SuperSecretPassword123";
    char str[64];

    printf("Ive guarded the flag with a strong password. Youll never get it!\n");
    printf("Enter the password to access the flag: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character from the input

    if (strcmp(str, passwd) == 0)
    {
        printf("H-How did you...\n");
        system("cat flag.txt");
    }
    else
    {
        printf("Incorrect password! Told ya!\n");
    }

    return 0;
}