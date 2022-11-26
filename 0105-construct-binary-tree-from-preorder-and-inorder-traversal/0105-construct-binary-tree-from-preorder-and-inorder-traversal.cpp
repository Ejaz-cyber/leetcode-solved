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
    map<int, int> mp;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // map<int, int> mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int preInd = 0;
        TreeNode * root = build(preorder, inorder, preInd, 0, inorder.size()-1);
        
        return root;
        
    }
    
    TreeNode * build(vector<int>& preorder, vector<int>& inorder,
                    int &preInd, int inStrt, int inEnd){
        
        if(preInd == preorder.size() || inStrt > inEnd){
            return NULL;
        }
        
        int ele = preorder[preInd];
        int pos;
        // for(int i=inStrt; i<=inEnd; i++){
        //     if(inorder[i] == ele){
        //         pos = i;
        //     }
        // }
        
        pos = mp[ele];
        
        TreeNode * root = new TreeNode(ele);
        preInd++;
        root->left = build(preorder, inorder, preInd, inStrt, pos - 1);
        
        root->right = build(preorder, inorder, preInd, pos+1, inEnd);
        
        return root;
        
        
        
    }
    
};