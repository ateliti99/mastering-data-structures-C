#include <stdio.h>

int main(int argc, char *argv){
    //char s_stack[] = "hello";
    char *s_heap = "hello";
    int i;

    // Print the string
    //printf("%p\n", s_stack);
    printf("%p\n", s_heap);

    // Find the lenght of the string
    for(i = 0; s_heap[i] != '\0'; i++){}
    printf("String lenght %d", i);

}