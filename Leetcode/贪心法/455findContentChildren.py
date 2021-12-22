class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        r = 0
        g.sort()
        s.sort()
        for p in g :
            for k in s :
                if k >= p : 
                    r = r + 1
                    s.remove(k)
                    break
        
        return r
