#ifndef B706A29E_7A7E_4E6C_8411_7B99E78C5609
#define B706A29E_7A7E_4E6C_8411_7B99E78C5609

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* top_elem;
    int* elements;
    int size;
} Stack;

Stack* createStack(int size){
    Stack* stack;

    stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL){
        return NULL;
    }

    stack->elements = (int*)malloc(size * sizeof(int));
    if(stack->elements == NULL){
        free(stack);  // Free previously allocated memory to avoid memory leak.
        return NULL;
    }

    stack->top_elem = stack->elements + size - 1;
    stack->size = size;

    return stack;
}

void fillStack(Stack* stack){
    for(int i = 0; i < stack->size; i++){
        stack->elements[i] = i;
    }
}

void printStack(Stack* stack){
    for(int i = 0; i < stack->size; i++){
        printf("%d\n", stack->elements[i]);
    }
}

int stackTop(Stack* stack){
    int top_elem = *(stack->top_elem);
    return top_elem;
}

void push(Stack* stack, int value){
    int* new_elements = (int*)realloc(stack->elements, (stack->size + 1) * sizeof(int));
    if (new_elements == NULL) {
        // Memory allocation failed, handle error accordingly
        return;
    }

    stack->elements[stack->size] = value;
    stack->size++;
    stack->top_elem = stack->elements + stack->size - 1;
}

#endif /* B706A29E_7A7E_4E6C_8411_7B99E78C5609 */
