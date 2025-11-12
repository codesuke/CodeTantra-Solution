#include <stdio.h>
#include <stdlib.h>

// Function to sort the array
void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to find last occurrence using binary search
int binarySearchLast(int arr[], int n, int z) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == z) {
            result = mid;      // Store index
            low = mid + 1;     // Search right half
        } else if (arr[mid] < z) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int z;
    scanf("%d", &z);

    sort(arr, N);  // Sort the array

    int position = binarySearchLast(arr, N, z);
    printf("%d\n", position);

    return 0;
}