
// 给定一个二进制数组， 计算其中最大连续 1 的个数。

//  

// 示例：

// 输入：[1,1,0,1,1,1]
// 输出：3
// 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.


// 提示：

// 输入的数组只包含 0 和 1 。
// 输入数组的长度是正整数，且不超过 10,000。

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count = 0;
    int max_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count = count + 1;
        } 
        if (nums[i] == 0 || i == numsSize - 1) {
            if (count > max_count) {
                max_count = count;
                count = 0;
            } else {
                count = 0;
            }
        }
    }

    return max_count;
}

//从头遍历，O(n)