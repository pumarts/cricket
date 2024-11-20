#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 
int stack[SIZE];
int top = -1;

void push() {
    if (top ==SIZE - 1)
        printf("Stack Overflow\n");
    else {
        int item;
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        stack[++top] = item;
        printf("%d pushed onto stack\n", item);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else 
        printf("Popped element: %d\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void checkPalindrome() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    int isPalindrome = 1; 
    for (int i = 0; i <= top / 2; i++) { 
        if (stack[i] != stack[top - i]) { 
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) 
        printf("The elements form a palindrome.\n");
    else
        printf("The elements do not form a palindrome.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--------STACK OPERATIONS-----------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display\n");
        printf("5. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}