#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5000 

// Define the structure for a stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Global stacks
struct Stack* s1; // Used for enqueue
struct Stack* s2; // Used for dequeue

/**
 * @brief Initializes a stack.
 * @param s Pointer to the stack.
 */
void stack_init(struct Stack *s) {
    s->top = -1;
}

/**
 * @brief Checks if the stack is empty.
 * @param s Pointer to the stack.
 * @return 1 if empty, 0 otherwise.
 */
int stack_isEmpty(struct Stack *s) {
    return s->top == -1;
}

/**
 * @brief Checks if the stack is full.
 * @param s Pointer to the stack.
 * @return 1 if full, 0 otherwise.
 */
int stack_isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

/**
 * @brief Pushes a value onto the stack.
 * @param s Pointer to the stack.
 * @param value The value to push.
 */
void stack_push(struct Stack *s, int value) {
    if (stack_isFull(s)) {
        return;
    }
    s->arr[++(s->top)] = value;
}

/**
 * @brief Pops a value from the stack.
 * @param s Pointer to the stack.
 * @return The popped value, or -1 if empty (though per spec, we check first).
 */
int stack_pop(struct Stack *s) {
    if (stack_isEmpty(s)) {
        return -1; 
    }
    return s->arr[(s->top)--];
}

/**
 * @brief Enqueues a value into the queue (by pushing to s1).
 * @param value The value to enqueue.
 */
void queue_enqueue(int value) {
    stack_push(s1, value);
}

/**
 * @brief Dequeues a value from the queue.
 */
void queue_dequeue() {
    // If both stacks are empty, the queue is empty.
    if (stack_isEmpty(s1) && stack_isEmpty(s2)) {
        return;
    }

    // If s2 is empty, transfer all elements from s1 to s2.
    // This reverses their order, putting the oldest element at the top of s2.
    if (stack_isEmpty(s2)) {
        while (!stack_isEmpty(s1)) {
            stack_push(s2, stack_pop(s1));
        }
    }

    // Pop the front element from s2.
    stack_pop(s2);
}

/**
 * @brief Prints the final state of the queue.
 */
void queue_print() {
    if (stack_isEmpty(s1) && stack_isEmpty(s2)) {
        printf("Empty\n");
        return;
    }

    int first_print = 1;

    // Print elements in s2 (front of the queue)
    // These are already in correct pop order, so print top-to-bottom.
    for (int i = s2->top; i >= 0; i--) {
        if (!first_print) {
            printf(" ");
        }
        printf("%d", s2->arr[i]);
        first_print = 0;
    }

    // Print elements in s1 (back of the queue)
    // These are in reverse enqueue order, so print bottom-to-top.
    for (int i = 0; i <= s1->top; i++) {
        if (!first_print) {
            printf(" ");
        }
        printf("%d", s1->arr[i]);
        first_print = 0;
    }
    
    printf("\n");
}

int main() {
    // Allocate memory for the two stacks
    s1 = (struct Stack*)malloc(sizeof(struct Stack));
    s2 = (struct Stack*)malloc(sizeof(struct Stack));
    
    if (s1 == NULL || s2 == NULL) {
        return 1; // Memory allocation failed
    }

    // Initialize the stacks
    stack_init(s1);
    stack_init(s2);

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int operation_type;
        scanf("%d", &operation_type);

        if (operation_type == 1) {
            int value;
            scanf("%d", &value);
            queue_enqueue(value);
        } else if (operation_type == 2) {
            queue_dequeue();
        }
    }

    // Print the final queue
    queue_print();

    // Free the allocated memory
    free(s1);
    free(s2);

    return 0;
}