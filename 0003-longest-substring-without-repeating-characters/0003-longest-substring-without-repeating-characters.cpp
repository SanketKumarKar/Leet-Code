class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; //sliding window concept
        int l=0;
        int r=0;
        int maxL = 0;
        for(r; r<s.size(); r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxL = max(maxL, r-l+1);   
        }
        return maxL;
    }
};