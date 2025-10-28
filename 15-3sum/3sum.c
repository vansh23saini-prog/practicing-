#include <stdlib.h>

// Helper function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int cap = 1000; // Initial capacity for answers
    int** ans = malloc(cap * sizeof(int*));
    *returnColumnSizes = malloc(cap * sizeof(int));
    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 2; i++) {
        // Skip duplicates for i
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = numsSize - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                // Store triplet
                ans[*returnSize] = malloc(3 * sizeof(int));
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[left];
                ans[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                // Resize if out of space
                if(*returnSize >= cap) {
                    cap *= 2;
                    ans = realloc(ans, cap * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, cap * sizeof(int));
                }
                // Skip duplicates for left and right
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return ans;
}
