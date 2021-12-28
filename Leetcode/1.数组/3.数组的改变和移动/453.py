
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        m = min(nums)
        for n in nums :
            ans = ans + (n - m)
        
        return ans

"""
每次操作既可以理解为使 n-1 个元素增加 1，也可以理解使 1 个元素减少 1。
"""