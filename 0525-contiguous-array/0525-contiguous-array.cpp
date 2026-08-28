class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0]=-1;

        for(int i =0; i<arr.size(); i++){
            if(arr[i]==0){
                sum+= 1;
            }
            if(arr[i]==1){
                sum-= 1;
            }

            if(mp.find(sum)!=mp.end()){
                ans = max(ans, i-mp[sum]);
            } else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};