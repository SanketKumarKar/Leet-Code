class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int product1=nums[0]*nums[1]*nums[n-1];// sab no. neg last wala positive ya all num neg.
        int product2=nums[n-3]*nums[n-2]*nums[n-1];
        if(product1>product2) return product1;
        else return product2;
    }
}