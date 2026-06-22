class Solution:
    def merge(self, arr):

        arr.sort()

        res = [arr[0]]

        for start, end in arr[1:]:

            if res[-1][1] >= start:

                res[-1][1] = max(end, res[-1][1])

            else:
                res.append([start, end])

        return res