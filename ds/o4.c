#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void enqueue(int q[], int *front, int *rear, int item) {
    if ((*rear + 1) % SIZE == *front)
        printf("Queue is full. Enqueue not possible.\n");
    else 
    {
        if (*front == -1) 
            *front = *rear = 0;
        else
            *rear = (*rear + 1) % SIZE;
        q[*rear] = item;
        printf("%d enqueued to queue\n", item);
    }
}

void dequeue(int q[], int *front, int *rear) {
    if (*front == -1) 
        printf("Queue is empty. Dequeue not possible.\n");
    else 
    {
        printf("The item dequeued is %d\n", q[*front]);
        if (*front == *rear)  
            *front = *rear = -1;
        else 
            *front = (*front + 1) % SIZE;
    }
}

void display(int q[], int front, int rear) {
    if (front == -1) 
        printf("Queue is empty. Nothing to display.\n");
    else{
        printf("The elements in the queue are:\n");
        int i = front;
        while (1) {
            printf("Queue[%d] => %d\n", i, q[i]);
            if (i == rear) break; 
            i = (i + 1) % SIZE;
        }
    }
}

int main() {
    int q[SIZE];
    int front = -1, rear = -1; 
    int item, choice;
    while (1) {
        printf("\nEnter the option for circular queue:\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &item);
                enqueue(q, &front, &rear, item);
                break;
            case 2:
                dequeue(q, &front, &rear);
                break;
            case 3:
                display(q, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}