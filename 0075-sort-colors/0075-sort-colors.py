class Solution:
    def sortColors(self, arr: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # code here
        low = 0
        mid = 0
        high = len(arr) -1 
        # dutch national flag also, saw in reels
        while mid <= high:
            # low -  mid all 0 mid all 1s mid to high all 2
            if arr[mid] == 0:
                
                arr[mid] ,arr[low] = arr[low], arr[mid]
                mid += 1
                low += 1
                
            elif arr[mid] == 1:
                # 1 and 0 mai mid will move ahead 
                mid += 1
                
            elif arr[mid] == 2:
                arr[mid] ,arr[high] = arr[high], arr[mid]
                high -= 1
                # mid nahi bhadaya cause 1 ke aage saare 2 hi honge