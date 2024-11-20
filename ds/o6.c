#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
};

struct node *head = NULL;
int count = 0;
void create(struct node **new_node);
void insertBeg();
void insertEnd();
void display();
void deleteBeg();
void deleteEnd();

int main() {
    int choice, n, i;
    printf("-----------------MENU--------------------\n");
    printf("1 - Create a DLL of n employees\n");
    printf("2 - Display from beginning\n");
    printf("3 - Insert at end\n");
    printf("4 - Delete at end\n");
    printf("5 - Insert at beginning\n");
    printf("6 - Delete at beginning\n");
    printf("7 - Exit\n");
    printf("------------------------------------------\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    insertEnd();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertBeg();
                break;
            case 6:
                deleteBeg();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
}

void create(struct node **new_node) {
    *new_node = (struct node *)malloc(sizeof(struct node));
    (*new_node)->prev = NULL;
    (*new_node)->next = NULL;

    printf("Enter SSN, Name, Department, Designation, Salary, and Phone Number: ");
    scanf("%d %s %s %s %f %d", &(*new_node)->ssn, (*new_node)->name, (*new_node)->dept,
          (*new_node)->desg, &(*new_node)->sal, &(*new_node)->phno);
    count++;
}

void insertBeg() {
    struct node *new_node;
    create(&new_node);

    if (head == NULL) {
        head = new_node; 
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node; 
    }
}


void insertEnd() {
    struct node *new_node, *temp;
    create(&new_node);

    if (head == NULL) {
        head = new_node;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next; 
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked list elements from beginning:\n");
    while (temp != NULL) {
        printf("%d %s %s %s %.2f %d\n", temp->ssn, temp->name, temp->dept,
               temp->desg, temp->sal, temp->phno);
        temp = temp->next;
    }
    printf("Number of employees: %d\n", count);
}

void deleteBeg() {
    if (head == NULL) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted: %d %s %s %s %.2f %d\n", temp->ssn, temp->name,
           temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    struct node *temp = head;

    while (temp->next != NULL) 
       temp = temp->next;

    if (temp->prev != NULL)
       temp->prev->next = NULL;
    else
       head = NULL;
    printf("Deleted: %d %s %s %s %.2f %d\n", temp->ssn, temp->name,
        temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}