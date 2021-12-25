class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = dict()
        if len(nums) == 1 :
            return 1

        for i in nums :
            if i in m :
                m[i] = m[i] + 1
            else :
                m[i] = 1
        
        maxVal = max(m.values())
        maxKey = []
        for key in m :
            if m[key] == maxVal :
                maxKey.append(key)
        
        ans = []

        for k in maxKey :
            left = -1
            right = -1

            for i in range(len(nums)) :
                if nums[i] == k :
                    if left == -1 :
                        left = i
                    else :
                        right = i
            if right == -1 :
                ans.append(1)
            else :
                ans.append(right - left + 1)
        return min(ans)

#用哈希表做，故而要用python(C语言用uthash)
#循环两次，第一次找到频数最大的数，第二次找到最小子区间的长度。
#根据题解，修改哈希映射方式为 num->[频数, 第一次出现的位置, 最后一次出现的位置]