class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Traverse from the last digit backwards
    for (int i = n - 1; i >= 0; i--) {
        digits[i]++;  // increment current digit
        if (digits[i] < 10) {
            return digits; // no carry, done
        }
        digits[i] = 0; // carry over
    }

    // If all digits were 9, we need an extra digit at the front
    digits.insert(digits.begin(), 1);
    return digits;
    }
};