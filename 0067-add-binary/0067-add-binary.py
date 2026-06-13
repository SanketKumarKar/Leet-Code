class Solution:
    def addBinary(self, s1, s2):
		# code here
	    i = len(s1) - 1
	    j = len(s2) - 1
	    carry = 0
	    ans = []
	    while i >= 0 or j >=0 or carry:
		    # get curr bits
		    a = int(s1[i]) if i>=0 else 0 # if bits over and carry is still there
		    b = int(s2[j]) if j>=0 else 0 # if bits over and carry is still there
		    
		    # sum using xor formula
		    sum_ = a^b^carry
		    ans.append(str(sum_))
		    
		    # compute carry
		    carry = (a&b) | (a&carry) | (b&carry)
		    
		    i-=1
		    j-=1
	    # reverse ans ans return and remove leading zeros
	    return ''.join(ans[::-1]).lstrip('0') or '0' #leftsrip 