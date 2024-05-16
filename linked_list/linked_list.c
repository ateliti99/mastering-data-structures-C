#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Main function
int main() {
    // Declare pointers to three nodes
    Node* node0;
    Node* node1;
    Node* node2;
    int value;

    // Create three nodes with values 0, 1, and 2
    node0 = createNode(0);
    node1 = createNode(1);
    node2 = createNode(2);

    // Set up the links between the nodes
    // node0 is the first node, so its previous node is NULL
    node0->prev = NULL;
    // Set the value of node0 to 0
    node0->value = 0;
    // Set the next node of node0 to node1
    node0->next = node1;

    // Set up node1
    // The previous node of node1 is node0
    node1->prev = node0;
    // Set the value of node1 to 1
    node1->value = 1;
    // Set the next node of node1 to node2
    node1->next = node2;

    // Set up node2
    // The previous node of node2 is node1
    node2->prev = node1;
    // Set the value of node2 to 2
    node2->value = 2;
    // node2 is the last node, so its next node is NULL
    node2->next = NULL;

    // Print the values of all nodes in the linked list
    printLinkedList(node0);

    // Return 0 to indicate successful execution
    return 0;
}