class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();
        vector<int> d(n);

        // Manacher's algorithm for odd-length palindromes
        int l = 0, r = -1;

        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n &&
                   s[i - k] == s[i + k]) {
                k++;
            }

            d[i] = k;

            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        vector<int> left(n, 1), right(n, 1);

        // Longest palindrome ending exactly at each position
        // and longest palindrome starting exactly at each position
        for (int i = 0; i < n; i++) {
            int len = 2 * d[i] - 1;
            int start = i - d[i] + 1;
            int end = i + d[i] - 1;

            left[end] = max(left[end], len);
            right[start] = max(right[start], len);
        }

        // Propagate smaller nested palindromes to earlier end positions
        for (int i = n - 1; i > 0; i--) {
            left[i - 1] = max(left[i - 1], left[i] - 2);
        }

        // Propagate smaller nested palindromes to later start positions
        for (int i = 0; i < n - 1; i++) {
            right[i + 1] = max(right[i + 1], right[i] - 2);
        }

        // Prefix maximums: best palindrome ending at or before i
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i], left[i - 1]);
        }

        // Suffix maximums: best palindrome starting at or after i
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i], right[i + 1]);
        }

        long long ans = 0;

        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, 1LL * left[i] * right[i + 1]);
        }

        return ans;
    }
};