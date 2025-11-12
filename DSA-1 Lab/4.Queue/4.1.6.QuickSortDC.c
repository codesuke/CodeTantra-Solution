#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ... (partition and quickSort functions remain the same) ...

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p_index = partition(arr, low, high);
        quickSort(arr, low, p_index - 1);
        quickSort(arr, p_index + 1, high);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // Print the element
        printf("%d", arr[i]); 
        
        // Always print a space after the element, including the last one
        printf(" "); 
    }
    // Print a newline character at the very end
    printf("\n");
}

// Main function to handle input and call the sorting function
int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int arr[n]; 

    // Read the space-separated array elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }

    // Apply Quick Sort
    quickSort(arr, 0, n - 1); 

    // Print the sorted array with the required trailing space
    printArray(arr, n);

    return 0;
}