#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5000 

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % MAX_SIZE) == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        return; 
    }
    
    if (isEmpty()) {
        front = 0;
    }
    
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        return;
    }
    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void printQueue() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    
    int i = front;
    while (1) {
        printf("%d", queue[i]);
        
        if (i == rear) {
            break;
        }
        
        printf(" ");
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int operation_type;
        scanf("%d", &operation_type);

        if (operation_type == 1) {
            int value;
            scanf("%d", &value);
            enqueue(value);
        } else if (operation_type == 2) {
            dequeue();
        }
    }

    printQueue();

    return 0;
}