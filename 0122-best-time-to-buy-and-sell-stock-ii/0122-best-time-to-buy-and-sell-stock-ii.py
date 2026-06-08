class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        # observation ery day when stock rises from 
        # the previous day the difference is the profit        
        for i in range(1,len(prices)):
            
            if prices[i]>prices[i-1]:
                
               profit += prices[i]-prices[i-1]
               
        return profit