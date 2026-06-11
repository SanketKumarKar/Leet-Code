class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        nums.sort()
        
        result = 1
        
        for num in nums:
            
            if num == result:
                
                result+=1
                
            elif num > result:
                break
        return result