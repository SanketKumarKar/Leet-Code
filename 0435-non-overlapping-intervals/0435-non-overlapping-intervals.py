class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # code here
        intervals.sort()
        n = len(intervals)
        count = 0
        i = 1
        if n == 1:
            return 0
        prev_end = intervals[0][1]
        
        for i in range(1,n):
            # agar overalapping count++
            if intervals[i][0] < prev_end:
                
                count+=1 # keep track of no. of interval removed
                # less end wale ko keep karo big end time ko hatao to minimize overlaps
                prev_end = min(prev_end , intervals[i][1])
            else:
                
                prev_end =intervals[i][1]
        
        return count   