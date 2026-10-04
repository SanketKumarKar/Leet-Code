class Solution {
    public boolean checkValidString(String s) {
        int low = 0;
        int high = 0;

        for (char c : s.toCharArray()) {

            if (c == '(') {
                low++;
                high++;
            } 
            else if (c == ')') {
                low--;
                high--;
            } 
            else { // '*'
                low--;   // '*' can act as ')'
                high++;  // '*' can act as '('
            }

            // Even the maximum possibility has too many ')'
            if (high < 0) {
                return false;
            }

            // cannot be negative
            low = Math.max(low, 0);
        }

        return low == 0;
    }
}