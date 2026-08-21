class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        sort(nums.begin(), nums.end());
        int count = 0;

        while(l < h){
            int sum = nums[l] + nums[h];

            if(sum < target){
                count += h-l;
                l++;
            } else{
                h--;
            }
        }

        return count;
    }
};