/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *first = nullptr, *middle = nullptr;
    TreeNode *last = nullptr, *prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev != nullptr && root->val < prev->val) { // voilation condition
            if (first == nullptr) { // first voilated node /big
                first = prev;
                middle = root;
            } else {
                last = root; //second voilated node /small 
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;

        inorder(root);

        if (first != nullptr && last != nullptr) {
            swap(first->val, last->val); // aage jaake koi voilated elt tha
        } else if (first != nullptr && middle != nullptr) {
            swap(first->val, middle->val); // agal bagal wale swap karo
        }
    }
};