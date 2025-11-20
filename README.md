# T1. Implement a command-line calculator that performs basic arithmetic operations (, , , ). Must use a switch statement for operation selection and include input validation to prevent division by zero.

#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

    // Prompt for first number
    printf("Enter the first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Error: Invalid input for first number.\n");
        return 1;
    }

    // Prompt for operator
    printf("Enter the operator (+, -, *, /): ");
    if (scanf(" %c", &operator) != 1) {
        printf("Error: Invalid input for operator.\n");
        return 1;
    }

    // Prompt for second number
    printf("Enter the second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Error: Invalid input for second number.\n");
        return 1;
    }

    // Perform calculation using switch statement
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            break;
        default:
            printf("Error: Invalid operator. Please use +, -, *, or /.\n");
            return 1;
    }

    return 0;
}
# T2. Create a program that uses a structto define student records (Name, ID, Grade). Implement functions to add new records and view all records stored in a simple array of structures.

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the Student struct
typedef struct {
    char name[50];
    int id;
    float grade;
} Student;

// Global array to store students
Student students[MAX_STUDENTS];
int student_count = 0;

// Function to add a new student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Maximum number of students reached.\n");
        return;
    }

    Student new_student;

    printf("Enter student name: ");
    scanf(" %[^\n]", new_student.name);  // Read string with spaces

    printf("Enter student ID: ");
    scanf("%d", &new_student.id);

    printf("Enter student grade: ");
    scanf("%f", &new_student.grade);

    students[student_count] = new_student;
    student_count++;

    printf("Student added successfully!\n");
}

// Function to view all students
void view_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("Grade: %.2f\n", students[i].grade);
        printf("--------------------\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nStudent Record System\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
# T3. Write a program to implement a dynamic array (like a resizable list). The program must demonstrate the use of malloc or calloc to allocate the initial array and realloc to expand the array's size when it becomes full.

#include <stdio.h>
#include <stdlib.h>

// Define a struct for the dynamic array
typedef struct {
    int *array;       // Pointer to the array
    size_t size;      // Current number of elements
    size_t capacity;  // Current capacity of the array
} DynamicArray;

// Function to initialize the dynamic array
void init_dynamic_array(DynamicArray *da, size_t initial_capacity) {
    da->array = (int *)malloc(initial_capacity * sizeof(int));
    if (da->array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    da->size = 0;
    da->capacity = initial_capacity;
    printf("Dynamic array initialized with capacity %zu.\n", initial_capacity);
}

// Function to add an element to the dynamic array
void add_element(DynamicArray *da, int value) {
    // Check if the array is full
    if (da->size == da->capacity) {
        // Double the capacity
        size_t new_capacity = da->capacity * 2;
        int *new_array = (int *)realloc(da->array, new_capacity * sizeof(int));
        if (new_array == NULL) {
            printf("Error: Memory reallocation failed.\n");
            exit(1);
        }
        da->array = new_array;
        da->capacity = new_capacity;
        printf("Array resized to capacity %zu.\n", new_capacity);
    }
    // Add the element
    da->array[da->size] = value;
    da->size++;
    printf("Added %d to the array. Current size: %zu\n", value, da->size);
}

// Function to display the elements in the dynamic array
void display_array(DynamicArray *da) {
    if (da->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (size_t i = 0; i < da->size; i++) {
        printf("%d ", da->array[i]);
    }
    printf("\n");
}

// Function to free the dynamic array
void free_dynamic_array(DynamicArray *da) {
    free(da->array);
    da->array = NULL;
    da->size = 0;
    da->capacity = 0;
}

int main() {
    DynamicArray da;
    size_t initial_capacity = 2;  // Start with a small capacity to demonstrate resizing

    // Initialize the dynamic array
    init_dynamic_array(&da, initial_capacity);

    // Demonstrate adding elements and resizing
    add_element(&da, 10);
    add_element(&da, 20);
    add_element(&da, 30);  // This should trigger a resize
    add_element(&da, 40);
    add_element(&da, 50);  // Another resize

    // Display the array
    display_array(&da);

    // Free the memory
    free_dynamic_array(&da);

    return 0;
}
# T4. Create a tool that reads text content from a file and applies a simple cryptographic shift (e.g., a Caesar Cipher or XOR operation) to each character. The program must save the result to a new file and include a function to decrypt it back to the original.

#include <stdio.h>
#include <stdlib.h>

// Define a struct for the dynamic array
typedef struct {
    int *array;       // Pointer to the array
    size_t size;      // Current number of elements
    size_t capacity;  // Current capacity of the array
} DynamicArray;

// Function to initialize the dynamic array
void init_dynamic_array(DynamicArray *da, size_t initial_capacity) {
    da->array = (int *)malloc(initial_capacity * sizeof(int));
    if (da->array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    da->size = 0;
    da->capacity = initial_capacity;
    printf("Dynamic array initialized with capacity %zu.\n", initial_capacity);
}

// Function to add an element to the dynamic array
void add_element(DynamicArray *da, int value) {
    // Check if the array is full
    if (da->size == da->capacity) {
        // Double the capacity
        size_t new_capacity = da->capacity * 2;
        int *new_array = (int *)realloc(da->array, new_capacity * sizeof(int));
        if (new_array == NULL) {
            printf("Error: Memory reallocation failed.\n");
            exit(1);
        }
        da->array = new_array;
        da->capacity = new_capacity;
        printf("Array resized to capacity %zu.\n", new_capacity);
    }
    // Add the element
    da->array[da->size] = value;
    da->size++;
    printf("Added %d to the array. Current size: %zu\n", value, da->size);
}

// Function to display the elements in the dynamic array
void display_array(DynamicArray *da) {
    if (da->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (size_t i = 0; i < da->size; i++) {
        printf("%d ", da->array[i]);
    }
    printf("\n");
}

// Function to free the dynamic array
void free_dynamic_array(DynamicArray *da) {
    free(da->array);
    da->array = NULL;
    da->size = 0;
    da->capacity = 0;
}

int main() {
    DynamicArray da;
    size_t initial_capacity = 2;  // Start with a small capacity to demonstrate resizing

    // Initialize the dynamic array
    init_dynamic_array(&da, initial_capacity);

    // Demonstrate adding elements and resizing
    add_element(&da, 10);
    add_element(&da, 20);
    add_element(&da, 30);  // This should trigger a resize
    add_element(&da, 40);
    add_element(&da, 50);  // Another resize

    // Display the array
    display_array(&da);

    // Free the memory
    free_dynamic_array(&da);

    return 0;
}
# T5. Implement a Singly Linked List using C structures. The program must demonstrate the ability to perform three operations: insertion at the head, deletion of a specific node by value, and traversal (printing all nodes).
 
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
