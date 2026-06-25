class Solution:

    def searchRange(self, arr, target):

        # using binary search 
        def firstOcc():

            l = 0
            h = len(arr) - 1
            ans = -1

            while l <= h:

                mid = (l + h) // 2

                if arr[mid] == target:

                    ans = mid
                    h = mid - 1      # go left

                elif arr[mid] < target:

                    l = mid + 1

                else:
                    h = mid - 1

            return ans

        # last occurrence
        def lastOcc():

            l = 0
            h = len(arr) - 1
            ans = -1

            while l <= h:

                mid = (l + h) // 2

                if arr[mid] == target:

                    ans = mid
                    l = mid + 1      # go right

                elif arr[mid] < target:

                    l = mid + 1

                else:
                    h = mid - 1

            return ans

        first = firstOcc()

        last = lastOcc()

        return first, last
       