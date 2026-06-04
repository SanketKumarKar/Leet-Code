class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        // CLEAN KARO STRING KO
        for(char ch : s) {
            if(isalnum(ch)) {
                t += tolower(ch);
            }
        }
        // two pointer technique use karenege
        int left = 0;
        int right = t.size() - 1;
        while(left < right) {
            if(t[left] != t[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};