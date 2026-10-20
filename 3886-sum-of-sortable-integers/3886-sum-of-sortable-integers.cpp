class Solution {
public:
    bool isRotation(vector<int>& nums, vector<int>& sorted, int start, int k) {
        // Build KMP LPS array for the target sorted block
        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (sorted[start + i] == sorted[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Searching target inside two virtual copies of the block.
        // Only 2*k - 1 elements are needed.
        int len = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int value = nums[start + (i % k)]; //%2 saving space

            while (len > 0 && value != sorted[start + len]) {
                len = lps[len - 1];
            }

            if (value == sorted[start + len]) {
                len++;
            }

            if (len == k) {
                return true;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            for (int i = 0; i < n; i += k) {
                if (!isRotation(nums, sorted, i, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};