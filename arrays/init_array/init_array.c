#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 5;
    int *p;

    // Allocate memory for the array in the heap
    p = (int*)malloc(size*sizeof(int));
    
    // Place series inside the array
    for(int i = 0; i < size; i++){
        p[i] = i;
    }

    // Print the allocated array
    for(int i = 0; i < size; i++){
        printf("%d ", p[i]);
    }
}