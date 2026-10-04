class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to use two pointers
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        // Iterate through each number
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            // Use two pointers to find pairs that sum to -nums[i]
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }
};