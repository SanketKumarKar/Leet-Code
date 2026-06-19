class Solution:
    def isHappy(self, n: int) -> bool:
        # agar cacl karte wakt same result aaa gya kuch toh phir 
        # it is a loop to return false
        seen = set()

        while n != 1:

            if n in seen:
                return False

            seen.add(n)

            total = 0

            while n > 0:
                digit = n % 10
                total += digit * digit
                n //= 10

            n = total

        return True