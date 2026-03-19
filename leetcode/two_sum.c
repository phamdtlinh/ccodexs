#include <stdio.h> 
int *twoSum(int *nums, int numsSize, int target, int *returnSize);
unsigned int hash(int key, int size);

int main(void) {
    int numsSize = 10;
    int nums[numsSize] = {1, 7, 2, 4, 6, 3, 1, 5, 9, 8};
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (max < nums[i]) max = nums[i];
    }
    int ht[max] = {-1};
    for (int i = 0; i < numsSize; i++) {
        ht[hash(nums[i], numsSize)] = i;
    }
    return 0;
}

unsigned int hash(int key, int size) {
    return key % size;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (max < nums[i]) max = nums[i];
    }
    int ht[max] = {-1};
    for (int i = 0; i < numsSize; i++) {
        ht[hash(nums[i], numsSize)] = i;
    }
}
