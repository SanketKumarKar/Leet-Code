class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        // Find next greater element for every value in nums2
        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // Remaining elements have no next greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Build the answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};