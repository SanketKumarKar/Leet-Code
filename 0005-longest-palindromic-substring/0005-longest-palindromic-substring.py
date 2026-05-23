class Solution(object):

    def expand(self, s, left, right):

        while (
            left >= 0 and
            right < len(s) and
            s[left] == s[right]
        ):
            left -= 1
            right += 1

        return s[left + 1:right]


    def longestPalindrome(self, s):

        ans = ""

        for i in range(len(s)):

            # odd length palindrome
            odd = self.expand(s, i, i)

            # even length palindrome
            even = self.expand(s, i, i + 1)

            if len(odd) > len(ans):
                ans = odd

            if len(even) > len(ans):
                ans = even

        return ans