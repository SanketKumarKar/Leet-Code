class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        // code here
        unordered_map <string , vector<string>> mp;
        // sorted s as key aur uske related string ko add karo
        for (string s : arr){
            
            string key = s;
            
            sort(key.begin(), key.end());
            
            mp[key].push_back(s);
            
        }
        
        vector<vector<string>> ans;
        
        for (auto it : mp){
            
            ans.push_back(it.second);
        }
        
        return ans;
    }
};