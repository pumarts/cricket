#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[10], name[20],branch[10];
    int sem ,ph;
    struct node *next;
};

struct node *first = NULL; 
int count = 0;
void create(struct node **new_node);
void insertFront();
void insertLast();
void deleteFront();
void deleteLast();
void display();

int main() {
    int choice, m, i;
    printf("\n-->MENU<--\n");
    while (1) {
        printf("1. Create a SLL\n");
        printf("2. Display the records\n");
        printf("3. Insert at the last\n");
        printf("4. Delete at the last\n");
        printf("5. Insert at the front\n");
        printf("6. Delete at the front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the number of student records to be created: ");
                scanf("%d", &m);
                for (i = 0; i < m; i++) 
                    insertLast();
                break;
            case 2:
                display();
                break;
            case 3:
                insertLast();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}

void create(struct node **new_node) {
    *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Student details:\n");
    printf("Enter USN: ");
    scanf("%s", (*new_node)->usn);
    printf("Enter Name: ");
    scanf("%s", (*new_node)->name);
    printf("Enter Branch: ");
    scanf("%s", (*new_node)->branch);
    printf("Enter Semester: ");
    scanf("%d", &(*new_node)->sem);
    printf("Enter Phone Number: ");
    scanf("%d", &(*new_node)->ph);
    (*new_node)->next = NULL;
    count++;
}

void insertFront() {
    struct node *new_node;
    create(&new_node);
    if (first == NULL) 
        first = new_node;
    else{
        new_node->next = first;
        first = new_node;
    }
}

void insertLast() {
    struct node *new_node, *temp;
    create(&new_node);

    if (first == NULL)
        first = new_node;
    else {
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteFront() {
    if (first == NULL) {
        printf("\nNo nodes in the list\n");
        return;
    }
    struct node *temp = first;
    first = first->next;
    free(temp);
    count--;
}

void deleteLast() {
    if (first == NULL) {
        printf("\nNo nodes in the list\n");
        return;
    }
    struct node *temp1 = first, *temp2 = NULL;
    while (temp1->next != NULL) {
       temp2 = temp1;
       temp1 = temp1->next; 
    }

    if (temp2 != NULL)  
       temp2->next = NULL;
    else { 
       first = NULL;
    }
   free(temp1);
   count--;
}

void display() {
    if (first == NULL) {
        printf("\nNo nodes to display\n");
        return;
    }

    struct node *temp = first;
    
    printf("There are %d number of nodes in the list\n", count);
    
    printf("Student Details are:\n");
    printf("USN \tNAME \tBRANCH \tSEM \tPHONE NUMBER\n");
    
    printf("\n-----------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-10s %-20s %-10s %-5d %-10d\n", 
               temp->usn, temp->name, temp->branch, temp->sem, temp->ph);
        temp = temp->next;
    }
}