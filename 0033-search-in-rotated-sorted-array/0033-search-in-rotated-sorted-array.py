
class Solution:
    def search(self, arr, key):
        # code here
        l = 0
        h = len(arr) -1
        
        while l <= h:
            
            mid = (l+h) // 2
            
            if arr[mid] == key:
                
                return mid
            # left half is sorted
            if arr[l] <= arr[mid]:
                
                if arr[l] <= key < arr[mid]:
                    
                    h = mid - 1
                else:
                    
                    l = mid + 1
            # right half is sorted
            else:
                
                if arr[mid] < key <= arr[h]:
                    
                    l = mid + 1
                
                else:
                    
                    h = mid - 1
                    
        return -1        