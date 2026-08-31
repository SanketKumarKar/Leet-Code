class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int> curr, vector<int> formed) {

        if (curr.empty()) {
            ans.push_back(formed);
            return;
        }

        for (int i = 0; i < curr.size(); i++) {

            // Skip duplicate choices
            if (i > 0 && curr[i] == curr[i - 1])
                continue;

            int x = curr[i];

            // Remove current element
            curr.erase(curr.begin() + i);

            // Add it to formed
            formed.push_back(x);

            // Recursively generate
            solve(curr, formed);

            // Backtrack
            formed.pop_back();

            // Restore curr
            curr.insert(curr.begin() + i, x);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> formed;

        solve(nums, formed);

        return ans;
    }
};