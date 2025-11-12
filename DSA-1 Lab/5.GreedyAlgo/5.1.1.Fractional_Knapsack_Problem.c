#include <stdio.h>
#include <stdlib.h>

// A structure to store item details
struct Item {
    int value;
    int weight;
    double ratio; // value-to-weight ratio
};


int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;

    if (itemB->ratio > itemA->ratio) {
        return 1; // itemB comes before itemA
    } else if (itemB->ratio < itemA->ratio) {
        return -1; // itemA comes before itemB
    }
    return 0; // Ratios are equal
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // 1. Sort items based on their value/weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compareItems);

    double totalValue = 0.0;
    int currentCapacity = capacity;

    // 2. Iterate through sorted items and add them to the knapsack
    for (int i = 0; i < n; i++) {
        // If the knapsack is full, stop
        if (currentCapacity == 0) {
            break;
        }

        // 3. If the entire item fits, take all of it
        if (items[i].weight <= currentCapacity) {
            currentCapacity -= items[i].weight;
            totalValue += items[i].value;
        } 
        // 4. If only a fraction fits, take the fraction
        else {
            // Calculate the fraction of the item to take
            double fraction = (double)currentCapacity / items[i].weight;
            
            // Add the value of that fraction
            totalValue += items[i].value * fraction;
            
            // Knapsack is now full
            currentCapacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    
    // Read the number of items and knapsack capacity
    scanf("%d %d", &n, &capacity);

    struct Item *items = malloc(n * sizeof(struct Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read all items and calculate their ratios
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        
        // Calculate ratio, ensure floating-point division
        if (items[i].weight > 0) {
            items[i].ratio = (double)items[i].value / items[i].weight;
        } else {
            // Handle edge case of zero weight, if value is also 0, ratio is 0
            // If value > 0, it's infinitely valuable (treat as very large)
            items[i].ratio = (items[i].value > 0) ? __DBL_MAX__ : 0.0;
        }
    }

    // Calculate the maximum value
    double maxValue = fractionalKnapsack(items, n, capacity);

    // Print the result formatted to 6 decimal places
    printf("%.6f\n", maxValue);

    // Free allocated memory
    free(items);

    return 0;
}