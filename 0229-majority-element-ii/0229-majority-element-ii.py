class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # dict banao to store freq for faster access
        freq = {}
        n = len(nums)
        # loop through arr and count and store freq in dict
        for num in nums:
            freq[num] = freq.get(num,0)+1
        output = []
        # now check those elt jiski freq greater ho n/3 se
        for key, value in freq.items():
            if value > n//3:
                output.append(key)
        # sort and return
        output.sort()
        return output