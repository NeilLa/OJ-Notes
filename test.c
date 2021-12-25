# include <stdio.h>
int thirdMax(int* nums, int numSize);

int main() {
    int nums[] = {1, 2, 2, 4};

    int *a = findErrorNums(nums, 4, 2);
    

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *errorNums;
    errorNums = malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i + 1] != nums[i] + 1) {
            errorNums[0] = nums[i];
            errorNums[1] = nums[i] + 1;
        }
    }

    return errorNums;
}
