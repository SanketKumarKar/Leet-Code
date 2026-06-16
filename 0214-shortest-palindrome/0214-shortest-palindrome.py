class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # simple hai lps nikalo joh palindrome ho 
        # palindrome ki condition hoti hai s = reverse(s)
        # so agar prefix  ==  suffix of reverse(s) --> longest palindrome
        temp = s + "$" + s[::-1]
        n = len(temp)
        
        lps = [0] * n #LPS arr
        length = 0
        # build LPS arr
        i = 1
        while i < n:
            
            if temp[i] == temp[length]:
                length += 1
                lps[i] = length
                i += 1
                
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        # lps[-1] matlab start se longest palindrom ke length/postion jaha se rem char left
        rem = s[lps[-1]:] # grab the rem char 
        # flip and join the org string
        return rem[::-1]+s