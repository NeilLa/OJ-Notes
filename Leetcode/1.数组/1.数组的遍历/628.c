int maximumProduct(int* nums, int numsSize){
    int min = -1001;
    int max = 1001;
    int fir = min;
    int sec = min;
    int thi = min;
    int Ffir = max;
    int Fsec = max;

    for (int i = 0; i < numsSize; i++) {
        
        if (nums[i] >= fir) {
            thi = sec;
            sec = fir;
            fir = nums[i];
        } else if (nums[i] >= sec && fir > nums[i]) {
            thi = sec;
            sec = nums[i];
        } else if (nums[i] >= thi && sec > nums[i]) {
            thi = nums[i];
        }

        if (nums[i] <= Ffir) {
            Fsec = Ffir;
            Ffir = nums[i];
        } else if (nums[i] <= Fsec && nums[i] > Ffir) {
            Fsec = nums[i];
        }
    }

    int sol1 = fir * sec * thi;
    int sol2 = Ffir * Fsec * fir;

    if (sol1 > sol2) {
        return sol1;
    } else {
        return sol2;
    }

}


/*
如果正数（0）的数量>=3, 直接返回最大的三个正数的积 （三个最大数）
如果正数（0）的数量=2，返回最大的负数和两个正数的积 （三个最大数）
如果正数（0）的数量=1， 返回两个最小负数的积和正数的积 （两个最小负数）
如果正数（0）的数量<=0, 返回最大的三个负数的乘积（三个最大数）

故，最大积只可能为三个最大数乘积以及两个最小值乘积和一个最大值的乘积，
均计算出来，比较后输出。
*/