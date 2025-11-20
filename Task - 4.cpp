//T4. Create a tool that reads text content from a file and applies a simple cryptographic shift (e.g., a Caesar Cipher or XOR operation) to each character. The program must save the result to a new file and include a function to decrypt it back to the original.

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

