class Solution {
  public:
    int lengthOfLongestSubstring(string &s) {
        // code here
        int count = 0;
        string temp ="";
        int n = s.size();
        int ans = 0;
        
        for(char x : s){
            
            while(temp.find(x)!=string::npos){ // shrink window  till that repeat char
                temp.erase(0,1); // 0th pos se 1 char remove
            }
            
            temp +=x; // add the curr char in the window
            ans = max(ans, (int)temp.size()); // keep max ans
        }
        
        return ans;
    }
};
