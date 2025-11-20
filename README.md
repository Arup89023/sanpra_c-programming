# sanpra_c-programming
This repository contains C programs and projects developed during my internship at Sanpra Consultancy Services. It includes topics like functions, arrays, pointers, and file handling. Projects such as a Student Management System and Calculator showcase my coding, debugging, and problem-solving skills in C programming.
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
