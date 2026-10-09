class Solution(object):
    def isGood(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        nums.sort()
        for i in range(0, n):
            if(i == n-1):
                return (nums[n-1] == n-1) 
            if(nums[i]!=i+1):
                return False
        return True
        