#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5000 

// Structure to store an element of the priority queue
struct Node {
    int value;
    int priority;
};

// Global heap array and its current size
struct Node heap[MAX_SIZE];
int heapSize = 0;


void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}


void heapifyUp(int i) {
    // While the node is not the root and its priority is less
    // than its parent's priority, swap them.
    int parent = (i - 1) / 2;
    while (i > 0 && heap[i].priority < heap[parent].priority) {
        swap(&heap[i], &heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}


void heapifyDown(int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and has a smaller priority
    if (left < heapSize && heap[left].priority < heap[smallest].priority) {
        smallest = left;
    }

    // Check if right child exists and has a smaller priority
    if (right < heapSize && heap[right].priority < heap[smallest].priority) {
        smallest = right;
    }

    // If the smallest is not the current node, swap them
    // and recursively call heapifyDown on the new smallest.
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}


void enqueue(int value, int priority) {
    if (heapSize >= MAX_SIZE) {
        return; // Queue is full
    }
    
    // 1. Add the new element to the end of the heap
    struct Node newNode;
    newNode.value = value;
    newNode.priority = priority;
    
    heap[heapSize] = newNode;
    int currentIndex = heapSize;
    heapSize++;

    // 2. Restore the heap property by bubbling up
    heapifyUp(currentIndex);
}


void dequeue() {
    if (heapSize == 0) {
        return; // Queue is empty
    }

    // 1. The element to remove is the root (heap[0])
    // 2. Replace the root with the last element in the heap
    heap[0] = heap[heapSize - 1];
    
    // 3. Decrease the heap size
    heapSize--;

    // 4. Restore the heap property by bubbling down the new root
    heapifyDown(0);
}

/**
 * @brief Prints the final state of the priority queue.
 */
void printQueue() {
    if (heapSize == 0) {
        printf("Empty\n");
        return;
    }

    // Print all elements in the heap array
    for (int i = 0; i < heapSize; i++) {
        printf("%d (%d)", heap[i].value, heap[i].priority);
        if (i < heapSize - 1) {
            printf(" ");
        }
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
            // Enqueue operation
            int value, priority;
            scanf("%d %d", &value, &priority);
            enqueue(value, priority);
        } else if (operation_type == 2) {
            // Dequeue operation
            dequeue();
        }
    }

    // Print the final queue
    printQueue();

    return 0;
}