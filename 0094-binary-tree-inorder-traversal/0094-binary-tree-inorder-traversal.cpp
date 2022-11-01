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
public:
    
    void inorder(TreeNode * node, vector<int>& ans){
        if(node == NULL) return;
        
        //left
        inorder(node->left, ans);
        // root node
        ans.push_back(node->val);
        // right
        inorder(node->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        // inorder = left node right
        inorder(root, ans);
        
        return ans;
    }
};