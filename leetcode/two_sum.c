#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20003

typedef struct {
	int key;
	int value;
	int occupied;
} Node;

Node hash_table[TABLE_SIZE] = {{0, 0, 0}};
int *twoSum(int *nums, int numsSize, int target, int *returnSize);
int get_hash(int key);
/*
void insert(int key, int val);
int find(int key);
*/


int main(void) {
	int arr[] = {2, 7, 11, 15, 2, 15};
	int returnSize = 0;
	int *result = twoSum(arr, 6, 9, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
	for (int i = 0; i < numsSize; i++) {
		int compliment = target - nums[i];
		int hash = get_hash(nums[i]);
		printf("%d\n", hash);
		printf("key: %d, value %d, occupied: %d\n", hash_table[hash].key, hash_table[hash].value, hash_table[hash].occupied);
		if (hash_table[get_hash(compliment)].occupied == 1 ) {
			int *result = malloc(2 * sizeof(*result));
			if (!result) {
				returnSize = 0;
				return NULL;
			}
			result[0] = hash_table[get_hash(compliment)].value;
			result[1] = i;
			*returnSize = 2;
			return result;
		}
		while (hash_table[hash].occupied) {
			hash = (hash + 1) % TABLE_SIZE;
			hash_table[hash].key = nums[i];
			hash_table[hash].value = i;
			hash_table[hash].occupied = 1;
		}
	}
	*returnSize = 0;
	return NULL;
}

int get_hash(int key) {
	int h = key % TABLE_SIZE;
	return (h < 0) ? (h + TABLE_SIZE) : h;
}
/*
void insert(int key, int val) {
	int idx = get_hash(key);
	while (hash_table[idx].occupied) {
		idx = (idx + 1) % TABLE_SIZE;
	}
	hash_table[idx].key = key;
	hash_table[idx].value = val;
	hash_table[idx].occupied = 1;
}

int find(int key) {
	int idx = get_hash(key);
	while (hash_table[idx].occupied) {
		if (hash_table[idx].key == key) return hash_table[idx].value;
		idx = (idx + 1) % TABLE_SIZE;
	}
	return -1;
}
*/