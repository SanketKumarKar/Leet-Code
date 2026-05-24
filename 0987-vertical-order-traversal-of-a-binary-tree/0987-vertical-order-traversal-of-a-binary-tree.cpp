class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        // node -> {row, col}
        q.push({root, {0, 0}});
        while(!q.empty()) {   
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;
            nodes.push_back({col, row, node->val});
            if(node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if(node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        
        sort(nodes.begin(), nodes.end());
        
        vector<vector<int>> ans;
        
        int prevCol = INT_MIN;
        
        for(auto &it : nodes) {
            
            int col, row, val;
            tie(col, row, val) = it;
            
            if(col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }
            
            ans.back().push_back(val);
        }
        
        return ans;
    }
};