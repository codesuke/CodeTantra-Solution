#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Doubly linked list node structure
typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(char *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->data, data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to split the doubly linked list
Node* split(Node *head) {
    Node *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    if (temp) temp->prev = NULL;
    return temp;
}

// Function to merge two sorted doubly linked lists
Node* merge(Node *first, Node *second) {
    // If first list is empty
    if (!first) return second;
    
    // If second list is empty
    if (!second) return first;
    
    // Compare strings lexicographically
    if (strcmp(first->data, second->data) <= 0) {
        first->next = merge(first->next, second);
        if (first->next) first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = merge(first, second->next);
        if (second->next) second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Merge sort for doubly linked list
Node* mergeSortDoubly(Node *head) {
    if (!head || !head->next) return head;
    
    Node *second = split(head);
    
    // Recursively sort both halves
    head = mergeSortDoubly(head);
    second = mergeSortDoubly(second);
    
    // Merge the sorted halves
    return merge(head, second);
}

char * mergeSort(char *Arr[], int ArrLen) {
    if (ArrLen == 0) {
        char *result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }
    
    // Create doubly linked list from array
    Node *head = createNode(Arr[0]);
    Node *current = head;
    
    for (int i = 1; i < ArrLen; i++) {
        Node *newNode = createNode(Arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    // Sort the doubly linked list
    head = mergeSortDoubly(head);
    
    // Calculate required memory for result string
    int totalLength = 0;
    current = head;
    while (current) {
        totalLength += strlen(current->data);
        if (current->next) totalLength += 4; // " -> " has 4 characters
        current = current->next;
    }
    
    // Allocate memory for result string
    char *result = (char*)malloc(totalLength + 1);
    result[0] = '\0';
    
    // Build the result string
    current = head;
    while (current) {
        strcat(result, current->data);
        if (current->next) {
            strcat(result, " -> ");
        }
        current = current->next;
    }
    
    // Free the linked list memory
    current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    
    return result;
}

int readStringArray(char *argsArray, char *arr[]) {
    int col = 0;
    char *token = strtok(argsArray, ",");
    while (token != NULL) {
        arr[col] = token;
        token = strtok(NULL, ",");
        col++;
    }
    return col;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("\n");
        return 0;
    }
    char *Arr[1000]; // Reasonable maximum size
    int ArrLen = readStringArray(argv[1], Arr);
    char *result = mergeSort(Arr, ArrLen);
    printf("%s\n", result);
    free(result);
    return 0;
}