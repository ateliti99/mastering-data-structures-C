#include <stdio.h>
#include "stack.h"

int main() {
    int size = 10;
    Stack* stack = createStack(size);
    if (stack == NULL) {
        printf("Failed to create stack.\n");
        return 1;
    }

    fillStack(stack);
    printStack(stack);
    printf("%d\n", stackTop(stack));
    push(stack, 10);
    printStack(stack);
    printf("%d\n", stackTop(stack));

    // Clean up
    free(stack->elements);
    free(stack);

    return 0;
}