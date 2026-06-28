class Solution:
    def maxDistance(self, stalls, k):

        # helper function
        # can we place k cows with minimum distance = dist ?
        def canPlace(stalls, k, dist):

            cows = 1                    # first cow at first stall
            last = stalls[0]

            for i in range(1, len(stalls)):

                # place next cow if distance condition satisfied
                if stalls[i] - last >= dist:

                    cows += 1
                    last = stalls[i]

                # all cows placed
                if cows == k:
                    return True

            return False


        # sort stalls first
        stalls.sort()

        # binary search on answer
        low = 1
        high = stalls[-1] - stalls[0]

        ans = 0

        while low <= high:

            mid = (low + high) // 2

            # if possible, try bigger distance
            if canPlace(stalls, k, mid):

                ans = mid
                low = mid + 1

            # not possible, reduce distance
            else:

                high = mid - 1

        return ans