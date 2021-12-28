int firstMissingPositive(int* nums, int numsSize){
    int i = 0;

    while (i < numsSize) {
        if (nums[i] <= 0 || nums[i] >= numsSize) {
            i = i + 1;
        } else {
            int x = nums[i] - 1; //此时x为nums[i]应该在的位置
            if (x == i) { //说明此时nums[i]已经在合适的位置
                i = i + 1;
            } else if (nums[x] != nums[i]) {
                int temp = nums[x];
                nums[x] = nums[i];
                nums[i] = temp;
            } else {
                i = i + 1;
            }
        }
    }

    //完成交换后，再循环一次

    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;     
        }
    }
    return numsSize + 1; //nums=[1]
}
/*
使用原地哈希，交换数组正元素，使得index = a[i] - 1 (即1对应0的位置)
这里注意，在交换完一次后循环变量i不能+1，因为换过来的新元素也需要考虑
从头再循环一次，第一个遇到的不正确的值的i + 1就是第一个缺失的正整数。
*/