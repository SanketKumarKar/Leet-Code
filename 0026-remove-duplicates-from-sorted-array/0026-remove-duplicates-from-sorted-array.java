import java.util.*;

class Solution {
    public int removeDuplicates(int[] nums) {
        // Write index for the next unique element
        int write = 1;

        // Iterate through the array starting from the second element
        for (int read = 1; read < nums.length; read++) {
            // If current element is not equal to the previous, it's unique
            if (nums[read] != nums[read - 1]) {
                nums[write] = nums[read];
                write++;
            }
        }
        // Return the length of the array with unique elements
        return write;
    }
}