//T5. Implement a Singly Linked List using C structures. The program must demonstrate the ability to perform three operations: insertion at the head, deletion of a specific node by value, and traversal (printing all nodes).

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the head
void insert_at_head(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    printf("Inserted %d at the head.\n", data);
}

// Function to delete a node by value
void delete_by_value(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete %d.\n", value);
        return;
    }

    Node *current = *head;
    Node *previous = NULL;

    // Check if the head node is the one to delete
    if (current->data == value) {
        *head = current->next;
        free(current);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Traverse the list to find the node
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If the value was not found
    if (current == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Delete the node
    previous->next = current->next;
    free(current);
    printf("Deleted %d from the list.\n", value);
}

// Function to traverse and print the list
void traverse(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;  // Initialize the head of the list

    // Demonstrate insertion at head
    insert_at_head(&head, 10);
    insert_at_head(&head, 20);
    insert_at_head(&head, 30);

    // Traverse and print the list
    traverse(head);

    // Demonstrate deletion by value
    delete_by_value(&head, 20);  // Delete existing value
    traverse(head);

    delete_by_value(&head, 50);  // Try to delete non-existing value
    traverse(head);

    delete_by_value(&head, 10);  // Delete head
    traverse(head);

    delete_by_value(&head, 30);  // Delete last remaining
    traverse(head);

    // Try to delete from empty list
    delete_by_value(&head, 40);

    return 0;
}

