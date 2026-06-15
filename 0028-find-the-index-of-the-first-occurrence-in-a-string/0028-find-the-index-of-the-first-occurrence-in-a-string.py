class Solution: 
    def strStr(self, txt, pat):
        res =[]
        n = len(txt)
        m = len(pat)
        # lps arr
        lps = [0]*m # longest prefix of pat[0:i] joki suffix bhi hai
        # making longest prefix suffix helper func
        def build_lps(lps, pat):
            
            len_ = 0
            lps[0] = 0 # lps[0] always 0
            
            i = 1
            while i < m:
                # agar char match ho
                if pat[i] == pat[len_]:
                    len_ +=1
                    lps[i] = len_
                    i += 1
                # agar na ho
                else: 
                    if len_ != 0:
                        # move len to place where lps existed to avoid bar bar ka checking
                        len_ = lps[len_ - 1]
                    else: #len = 0
                        lps[i]=0
                        i += 1
                        # scratch se nikalo karo lps from i
        build_lps(lps ,pat)
        i = 0
        j = 0
        
        while i < n:
            # check if match
            if txt[i] == pat[j]:
                i += 1
                j += 1

                if j == m:
                    return(i-j)
                    # agar match ho gya return
            else:
                #agar match nhi ho check from lps position
                if j != 0:
                    j = lps[j-1] # mismatch ke pehele pos se lps pos mai jao
                else:# agar patt ke start mai aage toh i ko aage bhadao check karo
                    i += 1
        return -1 #agar kuch bhi match nhi hua toh