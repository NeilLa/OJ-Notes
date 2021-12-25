/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp (int* a, int* b) {
    return *a - *b;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize){
    
    int* errorNums = malloc(sizeof(int) * 2);
    *returnSize = 2;
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0;
    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        int right = nums[i];
        if (right == left) {
            errorNums[0] = right;
        }
/*
寻找丢失的数字相对复杂，可能有以下两种情况：
如果丢失的数字大于 1 且小于 n，则一定存在相邻的两个元素的差等于 2，这两个元素之间的值即为丢失的数字；
如果丢失的数字是 1 或 n，则需要另外判断。
*/
        if (right - left == 2) {
            errorNums[1] = left + 1;
        }

        left = right;
    }

    if (nums[numsSize - 1] != numsSize) {
        errorNums[1] = numsSize;
    }
    return errorNums;
}

/*
    对于c语言的快排实现如下：
    在stdlib库中，

    qsort(*s, n, sizeof(int), cmp);
    其中s是参与排序的数组的地址
    n是需要排序的数量
    sizeof(int)是每个排序元素所占内存的大小
    cmp用以确定排序的顺序，cmp实现如下：
    
    int cmp(const void *a, const void *b) {
        return *(int*)a - *(int*)b; 此为从小到大排序
        return *(int*)b - *(int*)a; 此为从大到小排序
    }

    e.g 对一个长为1000的数组排序：
    int cmp(int* a, int* b) {
        return *a - *b
    }
    int a[1000];
    qsort(a, 1000, sizeof(int), cmp);

    对于其他数据类型的数组，相应的将int替换成float或char即可。
*/