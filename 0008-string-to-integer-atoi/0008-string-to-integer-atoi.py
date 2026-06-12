class Solution:
    def myAtoi(self, s):
        INT_MAX = 2147483647
        INT_MIN = -2147483648

        i = 0
        n = len(s)

        # Skip leading spaces
        while i < n and s[i] == ' ':
            i += 1

        # Check sign
        sign = 1
        if i < n and s[i] == '-':
            sign = -1
            i += 1
        elif i < n and s[i] == '+':
            i += 1

        # Read digits
        num = 0

        while i < n and s[i].isdigit():
            digit = int(s[i])

            # 4. Overflow check
            if num > (INT_MAX - digit) // 10:
                return INT_MAX if sign == 1 else INT_MIN
            # becuase ham left se right scan karre hai
            num = num * 10 + digit
            i += 1

        # 5. Return answer
        return sign * num