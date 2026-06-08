class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # keep track of min and max while traversing and diff is profit
        min_price = float('inf')
        max_profit = 0

        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)

        return max_profit