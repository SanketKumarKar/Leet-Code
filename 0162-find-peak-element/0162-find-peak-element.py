class Solution:
    def findPeakElement(self, arr: List[int]) -> int:
        # Code here
        l = 0
        h = len(arr) - 1
        while l < h:
            
            mid = (l+h) // 2
            
            if arr[mid] < arr[mid +1]:
                
                l = mid + 1
                
            else:
                
                h = mid
                
        return l