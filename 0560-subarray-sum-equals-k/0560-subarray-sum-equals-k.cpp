class Solution {
  public:
    int subarraySum(vector<int> &arr, int k) {
        // code here
        int count = 0;
        
        unordered_map<int,int> mp;
        
        int sum =0;
        
        mp[0]=1;
        
        for (int x : arr){
            
            sum+=x;
            // agar sum - k ka prefix sum mil jaye means waha se leke curr pos tak 
            // joh subb arr hai whi ans hai
            if(mp.find(sum-k)!=mp.end()){
                
                count+=mp[sum-k];
            }
            
            mp[sum]++;
            
        }
        
        return count;
    }
};