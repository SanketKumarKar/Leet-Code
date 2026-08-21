class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {

            int l = 0;
            int h = k - 1;

            while (l < h) {
                if ((arr[l] + arr[h]) > arr[k]) {
                    count += h - l;
                    h--;
                } else {
                    l++;
                }
            }
        }

        return count;
    }
};