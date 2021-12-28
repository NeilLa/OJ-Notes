int cmp (int* a, int* b) {
    return *a - *b;
}

int hIndex(int* citations, int citationsSize){
    if (citationsSize <= 1) {
        if (citations[0] == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    int res = 0;
    qsort(citations, citationsSize, sizeof(int), cmp);
    for (int h = 0; h <= citationsSize; h++) {
        int high;
        for (int i = 0; i < citationsSize; i++) {
            if (citations[i] >= h) {
                high = i;
                if (citationsSize - high == h) {
                    res = h;
                }
            }
        }
    }
    return res;
}
/*
h最大不会超过论文数量
最小为0
考虑二分或者迭代，因为还没有刷到二分法
本题使用迭代
*/