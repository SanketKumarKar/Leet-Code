from collections import Counter

class Solution:
    def firstUniqChar(self, s: str) -> int:
        # freq dict
        freq = Counter(s)
        # return 1st ch with freq 1
        for i in range(len(s)):
            if freq[s[i]]==1:
                return i
        return -1
       