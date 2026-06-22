class Solution:
    def merge(self, arr):
        # sort to make life ez
        arr.sort()

        res = [arr[0]]

        for start, end in arr[1:]:
            #compare prev range last elt to next range start elt
            if res[-1][1] >= start:
                #update the range
                res[-1][1] = max(end, res[-1][1])
            #if not overlapping append result
            else:
                res.append([start, end])

        return res