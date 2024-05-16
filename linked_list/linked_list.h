#ifndef C135B544_78EA_4C5C_8515_383C9F2306C9
#define C135B544_78EA_4C5C_8515_383C9F2306C9

#include <stdlib.h>

// Define a struct to represent a node in a double linked list
struct nodeStruct {
    // Pointer to the next node in the list
    struct nodeStruct* next;
    // Pointer to the previous node in the list
    struct nodeStruct* prev;
    // Integer value stored in the node
    int value;
};

typedef struct nodeStruct Node;


// Function to create a new node with a given value
Node* createNode(int value) {
    // Allocate memory for a new node using malloc
    Node* node = (Node*)malloc(sizeof(Node));

    // Check if the allocation was successful
    if (node == NULL) {
        // If allocation failed, return NULL to indicate an error
        return NULL;
    }

    // Initialize the node's value and pointers
    node->value = value;
    node->next = NULL;  // Initialize next pointer to NULL
    node->prev = NULL;  // Initialize previous pointer to NULL

    // Return the newly created node
    return node;
}

// Function to print the values of all nodes in a linked list
void printLinkedList(Node* node) {
    // Loop until we reach the end of the list (i.e., node is NULL)
    while (node!= NULL) {
        // Print the value of the current node
        printf("%d\n", node->value);
        // Move to the next node in the list
        node = node->next;
    }
}

#endif /* C135B544_78EA_4C5C_8515_383C9F2306C9 */
