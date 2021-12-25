class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        min = -(2 ** 31) - 1 #此处用c语言会溢出

        fir = sec = thi = min

        for i in nums :
            if i > fir :
                thi = sec
                sec = fir
                fir = i
            elif i > sec and fir > i :
                thi = sec
                sec = i
            elif i > thi and sec > i:
                thi = i
        
        if fir == min or sec == min or thi == min :
            return fir
        else :
            return thi