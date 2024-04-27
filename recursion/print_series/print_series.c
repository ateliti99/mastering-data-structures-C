#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void fun(int num)
{
    if(num > 0)
    {
        fun(num-1);
        printf("%d ", num);
    }
}

int main(int argc, char *argv[])
{
    int num;    
    char *endptr;
    long int number;

    errno = 0; // Reset errno for error checking

    // Check if the argument is provided
    if (argc < 2) 
    {
        printf("Please provide an argument!\n");
        return 1;
    }

    printf("The argument passed is: %s\n", argv[1]);
    num = strtol(argv[1], &endptr, 10);

    // Check for errors
    if (endptr == argv[1]) {
        printf("No digits found in the string\n");
    } else if (*endptr != '\0') {
        printf("Invalid characters found after the number\n");
    } else if (errno == ERANGE) {
        printf("Number out of range\n");
    }

    fun(num);
    return 0;
}