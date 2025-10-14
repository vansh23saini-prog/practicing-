#include <limits.h>

// Helper functions for min and max
int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * Finds the median of two sorted arrays with O(log(min(m, n))) time complexity.
 * @param nums1 The first sorted array.
 * @param nums1Size The size of the first array.
 * @param nums2 The second sorted array.
 * @param nums2Size The size of the second array.
 * @return The median of the two sorted arrays.
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to optimize the binary search.
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    int totalLength = m + n;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (totalLength + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Found the correct partition
            if (totalLength % 2 == 0) {
                return ((double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))) / 2.0;
            } else {
                return (double)max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // Code should never reach here with valid inputs
    return 0.0;
}
