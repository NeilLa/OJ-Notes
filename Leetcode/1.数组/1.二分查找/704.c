int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int middle = (right + left) / 2;

    while (left <= right) {
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] < target) {
            left = middle + 1;
            middle = (right + left) / 2;
        } else {
            right = middle - 1;
            middle = (right + left) / 2;
        }
    }
    return -1;

}

/* 
注意边界条件:
条件1： while(left < right) || while(left < right)
条件2： right = middle || right = middle - 1
*/