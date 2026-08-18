class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Binary search on smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int med = (n1 + n2 + 1) / 2;

        int low = 0;
        int high = n1;

        while (low <= high) {

            int mid1 = low + (high - low) / 2;
            int mid2 = med - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];

            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Total length is even
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                // Total length is odd
                return max(l1, l2);
            }

            // We took too many elements from nums1
            if (l1 > r2) {
                high = mid1 - 1;
            }

            // We took too few elements from nums1
            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};