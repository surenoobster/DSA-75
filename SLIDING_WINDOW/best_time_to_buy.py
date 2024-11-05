from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        max_prof = 0

        for i in range(1, len(prices)):
            max_prof = max(max_prof, prices[i] - min_price)
            min_price = min(min_price, prices[i])

        return max_prof
