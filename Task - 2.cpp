//T2. Create a program that uses a structto define student records (Name, ID, Grade). Implement functions to add new records and view all records stored in a simple array of structures.
 
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

