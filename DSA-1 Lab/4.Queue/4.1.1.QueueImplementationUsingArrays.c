#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Global pointers to the front and rear of the queue
// Initialize them to NULL (empty queue)
struct Node* front = NULL;
struct Node* rear = NULL;

/**
 * @brief Adds a new element to the end (rear) of the queue.
 * @param value The integer value to be added.
 */
void enqueue(int value) {
    // 1. Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // 2. Check if the queue is empty
    if (front == NULL) {
        // If empty, new node is both front and rear
        front = newNode;
        rear = newNode;
    } else {
        // 3. If not empty, add new node after the current rear
        rear->next = newNode;
        // Update rear to be the new node
        rear = newNode;
    }
}

/**
 * @brief Removes the element from the front of the queue.
 * As per the note, if the queue is empty, it does nothing.
 */
void dequeue() {
    // 1. Check if the queue is empty
    if (front == NULL) {
        return; // Do nothing if empty
    }

    // 2. Store the current front node to free it later
    struct Node* temp = front;

    // 3. Move the front pointer to the next node
    front = front->next;

    // 4. Check if the queue became empty after dequeuing
    if (front == NULL) {
        // If so, the rear must also be NULL
        rear = NULL;
    }

    // 5. Free the memory of the old front node
    free(temp);
}

/**
 * @brief Prints all elements currently in the queue from front to rear.
 * Prints "Empty" if the queue is empty.
 */
void printQueue() {
    // 1. Check if the queue is empty
    if (front == NULL) {
        printf("Empty\n");
        return;
    }

    // 2. Iterate from the front to the rear
    struct Node* current = front;
    while (current != NULL) {
        printf("%d", current->data);
        
        // Print a space if it's not the last element
        if (current->next != NULL) {
            printf(" ");
        }
        
        current = current->next;
    }
    printf("\n");
}

int main() {
    int q; // Number of operations
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int operation_type;
        scanf("%d", &operation_type);

        if (operation_type == 1) {
            // Enqueue operation
            int value;
            scanf("%d", &value);
            enqueue(value);
        } else if (operation_type == 2) {
            // Dequeue operation
            dequeue();
        }
    }

    // After all operations are done, print the final queue
    printQueue();

    return 0;
}