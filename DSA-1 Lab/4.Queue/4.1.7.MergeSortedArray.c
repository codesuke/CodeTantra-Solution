#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;      // Last valid element in nums1
    int j = n - 1;      // Last element in nums2  
    int k = m + n - 1;  // Last position in nums1
    
    // Merge from the end to avoid overwriting
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    
    // Copy remaining elements from nums2 if any
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int nums1[400], nums2[200];
    int m, n;
    
    // Read nums1 array (including zeros)
    int nums1Size = 0;
    while (scanf("%d", &nums1[nums1Size]) == 1) {
        nums1Size++;
        if (getchar() == '\n') break;
    }
    
    scanf("%d", &m);
    
    // Read nums2 array
    int nums2Size = 0;
    while (scanf("%d", &nums2[nums2Size]) == 1) {
        nums2Size++;
        if (getchar() == '\n') break;
    }
    
    scanf("%d", &n);
    
    // Merge arrays
    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    
    // Output the merged array
    printf("[");
    for (int i = 0; i < m + n; i++) {
        printf("%d", nums1[i]);
        if (i < m + n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    return 0;
}