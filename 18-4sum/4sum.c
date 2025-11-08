#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper to add result
void addResult(int*** result, int* returnSize, int nums[], int i, int j, int left, int right) {
    (*result)[*returnSize] = (int*)malloc(4 * sizeof(int));
    (*result)[*returnSize][0] = nums[i];
    (*result)[*returnSize][1] = nums[j];
    (*result)[*returnSize][2] = nums[left];
    (*result)[*returnSize][3] = nums[right];
    (*returnSize)++;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int cap = 2000;
    int** result = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    addResult(&result, returnSize, nums, i, j, left, right);
                    (*returnColumnSizes)[*returnSize - 1] = 4;
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
}
