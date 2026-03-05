// gcc pwn3.c -o pwn

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_SPACE 64

void init(long int *data)
{
    printf("Initializing data storage...\n");

    for (int i = 0; i < MAX_SPACE; i++)
    {
        data[i] = 0;
    }
}

void set_data(long int *data)
{
    int index;
    long int value;

    printf("Enter index to store data: ");
    scanf("%d", &index);
    if (index < 0 || index > MAX_SPACE - 1)
    {
        printf("Index out of range!\n\n");
        return;
    }
    if (index % 3 == 0)
    {
        printf("This slot is reserved for the admin!\n\n");
        return;
    }

    printf("Enter value to store: ");
    scanf("%ld", &value);

    data[index] = value;
    printf("Data stored at index %d\n\n", index);
}

void read_data(long int *data)
{
    int index;
    printf("Enter index to retrieve: ");
    scanf("%d", &index);

    if (index < 0 || index > MAX_SPACE - 1)
    {
        printf("Index out of range!\n\n");
        return;
    }
    if (index % 3 == 0)
    {
        printf("This slot is reserved for the admin!\n\n");
        return;
    }

    printf("Data at index %d: %li\n\n", index, data[index]);
}

void banner()
{
    printf("+-----------------------------------------+\n");
    printf("|        Welcome to Cloud Storage!        |\n");
    printf("|  This is a secure data storage program. |\n");
    printf("|       We hope you enjoy your stay!      |\n");
    printf("+-----------------------------------------+\n\n");
}

void exit_banner()
{
    printf("+-----------------------------------------+\n");
    printf("|     Thank you for using our service!    |\n");
    printf("|      We hope to see you again soon!     |\n");
    printf("+-----------------------------------------+\n\n");
}

void swap_data(long int *data)
{
    int index1, index2;
    long int temp;

    printf("Enter first index to swap: ");
    scanf("%d", &index1);
    if (index1 < 0 || index1 > 100 - 1)
    {
        printf("Index out of range!\n\n");
        return;
    }
    if (index1 % 3 == 0)
    {
        printf("This slot is reserved for the admin!\n\n");
        return;
    }

    printf("Enter second index to swap: ");
    scanf("%d", &index2);
    if (index2 < 0 || index2 > 100 - 1)
    {
        printf("Index out of range!\n\n");
        return;
    }
    if (index1 % 3 == 0)
    {
        printf("This slot is reserved for the admin!\n\n");
        return;
    }

    temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;

    printf("Data swapped between index %d and %d\n\n", index1, index2);
}

void run()
{
    banner();
    long int data[MAX_SPACE];
    init(data);

    // Admin data, reserved for admin use only
    data[0] = (long int)(uintptr_t)printf;

    while (1)
    {
        printf("-----------------\n");
        printf("**Cloud Storage**\n");
        printf("-----------------\n");
        printf("Choose an option:\n");
        printf("1. Store data\n");
        printf("2. Retreive data\n");
        printf("3. Swap data\n");
        printf("4. Quit\n");
        printf(">  ");

        int choice;
        scanf("%d", &choice);
        if (choice == 4)
        {
            break;
        }
        else if (choice == 1)
        {
            set_data(data);
        }
        else if (choice == 2)
        {
            read_data(data);
        }
        else if (choice == 3)
        {
            swap_data(data);
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }

    exit_banner();
    return;
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    run();

    return 0;
}