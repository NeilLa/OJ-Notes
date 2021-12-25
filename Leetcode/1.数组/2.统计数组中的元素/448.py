class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        num = set(nums)
        ans = []
        n = len(nums)
        for i in range(1, n + 1) :
            if i not in num :
                ans.append(i)

        return ans

#数量太大可以考虑布隆过滤器，但是布隆过滤器有误判率
#原地修改数组有待研究，实际还是使用set, 其核心思想在于n[i] = i
#本题如果使用for in list会超时，必须用set