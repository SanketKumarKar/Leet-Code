class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # currMax, currMin, maxProd
		# traverse karo in arr and keep track of min and max
		# anytime while multiplying the curr elt min can turn into max 
		# or max can turn into min 
		# keep track of max found till now
        maxProd = nums[0]
        currMin = nums[0]
        currMax = nums[0]

        for num in nums[1:]:

            # negative number can flip min ↔ max
            if num < 0:
                currMin, currMax = currMax, currMin

            currMax = max(num, currMax * num)
            currMin = min(num, currMin * num)

            maxProd = max(maxProd, currMax)

        return maxProd