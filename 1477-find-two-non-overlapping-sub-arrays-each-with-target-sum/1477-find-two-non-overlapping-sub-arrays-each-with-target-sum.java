class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;

        int[] best = new int[n];
        Arrays.fill(best, Integer.MAX_VALUE);

        int start = 0;
        int sum = 0;
        int minLen = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {

            sum += arr[i];

            while (sum > target) {
                sum -= arr[start];
                start++;
            }

            if (sum == target) {
                int len = i - start + 1;

                // Previous non-overlapping subarray
                if (start > 0 && best[start - 1] != Integer.MAX_VALUE) {
                    ans = Math.min(ans, len + best[start - 1]);
                }

                minLen = Math.min(minLen, len);
            }

            best[i] = minLen;
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}