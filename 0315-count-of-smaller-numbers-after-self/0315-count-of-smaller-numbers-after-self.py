class Solution:
    def countSmaller(self, nums):

        n = len(nums)
        ans = [0] * n

        # store (value, original_index)
        arr = [(nums[i], i) for i in range(n)]

        def merge(arr, l, mid, h):

            temp = []

            i = l
            j = mid + 1

            rightCount = 0   # how many smaller right elems moved ahead

            while i <= mid and j <= h:

                if arr[i][0] <= arr[j][0]:

                    # current left element has rightCount smaller elems after it
                    ans[arr[i][1]] += rightCount
                    temp.append(arr[i])
                    i += 1

                else:

                    # smaller element found on right
                    rightCount += 1
                    temp.append(arr[j])
                    j += 1

            # leftover left side
            while i <= mid:
                ans[arr[i][1]] += rightCount
                temp.append(arr[i])
                i += 1

            # leftover right side
            while j <= h:
                temp.append(arr[j])
                j += 1

            # copy back
            for k in range(len(temp)):
                arr[l + k] = temp[k]


        def mergeSort(arr, l, h):

            if l >= h:
                return

            mid = (l + h) // 2

            mergeSort(arr, l, mid)
            mergeSort(arr, mid + 1, h)

            merge(arr, l, mid, h)


        mergeSort(arr, 0, n - 1)

        return ans