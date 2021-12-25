class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        for e in nums :
            x = (e - 1) % n
            nums[x] = nums[x] + n
        
        ans = []
        
        for i, k in enumerate (nums) :
            if k > 2 * n :
                ans.append(i + 1)

        return ans
        
"""
本题目尝试使用原地哈希。
"""