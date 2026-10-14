/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int count = 0;

    void dfs(TreeNode root, int targetSum, long sum,
             HashMap<Long, Integer> map) {
        if (root == null) return;

        sum += root.val;

        count += map.getOrDefault(sum - targetSum, 0);

        map.put(sum, map.getOrDefault(sum, 0) + 1);

        dfs(root.left, targetSum, sum, map);
        dfs(root.right, targetSum, sum, map);

        map.put(sum, map.get(sum) - 1);
    }

    public int pathSum(TreeNode root, int targetSum) {
        count = 0;

        HashMap<Long, Integer> map = new HashMap<>();
        map.put(0L, 1);

        dfs(root, targetSum, 0L, map);
        return count;
    }
}