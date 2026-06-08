class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # set removes duplicates
        test = set(nums)
        # simple check the lenght now of test and list
        if len(nums) == len(test):
            return False
        else:
            return True
        
