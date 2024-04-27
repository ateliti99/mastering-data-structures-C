#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int *p, *q;
    int size_p = 10, size_q = 20;

    // Allocate memory for the first array
    p = (int*)malloc(size_p*sizeof(int));

    // Fill the allocated array
    for(int i = 0; i < size_p; i++){
        p[i] = i;
    }

    // Allocate memory for the second array
    q = (int*)malloc(size_q*sizeof(int));

    // Copy elements from p to q
    for(int i = 0; i < size_p; i++){
        q[i] = p[i];
    }

    // Fill the remaing array
    for(int i = size_p; i < size_q; i++){
        q[i] = i;
    }

    // Free memory of the first array
    free(p);
    // Re-point the first pointer to the new array
    p = q;
    q = NULL;

    // Check that the array is correctly print
    for(int i = 0; i < size_q; i++){
        printf("%d ", p[i]);
    }

    return 0;
}