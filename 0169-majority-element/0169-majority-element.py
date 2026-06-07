class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # moore'a voting algo 
        # simple hai set karo init candidate, count
        count = 0
        candidate = None
        for n in nums:
            # count jaise hi 0 ho jaye set new candidate
            if count == 0:
                candidate = n
            # agar candidate wala no. hai aur toh count + 1
            if candidate == n:
                count+=1
            # koi aur elt hai toh dec count
            else: 
                count-=1
        return candidate