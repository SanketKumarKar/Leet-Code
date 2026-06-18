class Solution:
    def hIndex(self, citations):
        #code here
        citations.sort()
        # sort kar diya
        n = len(citations)
        
        for i in range(n):
            
            if citations[i]  >= n - i: # check karo curr elt >= rem elt 
                
                return n - i # as remaining elt bade hi honge curr se
                
        return 0