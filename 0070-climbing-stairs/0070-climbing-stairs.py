class Solution:
    def climbStairs(self, n: int) -> int:
        # agar hame nth stair par jaana hai
        # we know we can take either 1 or 2 step
        # nth ke 1 step pehele ham n-1 stair par honge 
        # nth ke 2 step pehele ham n-2 stair par honge
        # no. of ways we can reach nth is no. of ways of (n-1) + (n-2)
        # n=1 ka ans we know 1 and for n=2 its 2
        
        #base case
        if n<3:
            return n
            
        a = 1
        b = 2
            
        for _ in range(3,n+1):
            
            curr = a + b
            a = b
            b = curr
            
        return b