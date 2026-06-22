class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevelNodes;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                currentLevelNodes.push_back(current->val);
                
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            
            result.push_back(currentLevelNodes);
        }
        
        return result;
    }
};
