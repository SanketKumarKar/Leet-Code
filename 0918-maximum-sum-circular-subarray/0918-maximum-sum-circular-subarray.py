class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # code here
        # observation:
        # if we remove the minSum(worst elts) the remaining 
        # elt are maxSum circularly
        # and also consider normal kadane
        total = sum(nums)
        
        Max = maxSum = nums[0]
        Min = minSum = nums[0]
        
        for num in nums[1:]:
            
            maxSum = max(maxSum+num, num)
            #keep track of max
            Max = max(maxSum, Max)
            
            minSum = min(minSum+num , num)
            # keep track of min
            Min = min(minSum, Min)
            
            # handle all num negitive case as subtracting 
            # minSum will make it positive and thus the wrong ans
        if Max<0:
            return Max
                
        return max(Max, total-Min)