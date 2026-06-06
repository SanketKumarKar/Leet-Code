class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        test = set(nums)
        if len(nums) == len(test):
            return False
        else:
            return True
        