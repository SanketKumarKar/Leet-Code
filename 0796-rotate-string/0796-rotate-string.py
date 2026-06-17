class Solution:
    def rotateString(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        return s in (t+t)