class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
    
        res = nums[0]
        maxEnding = nums[0]
        # sum karte raho jabtak sum se bada no. na mil jaye
        # agar mil gya toh us point se sum karte raho 
        # neg case hoga toh maxEnding apne aap chnage hokar max neg find karlega
        # same for postive no. case sabko add karega
        for i in range(1,len(nums)):
            # keep track of sum in the forming at the end of subarray
            maxEnding = max(maxEnding + nums[i], nums[i])
            # keep trac of the max sum
            res = max(res, maxEnding)
            
        return res