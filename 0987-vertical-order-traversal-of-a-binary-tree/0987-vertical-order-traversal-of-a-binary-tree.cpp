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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        map<int, map<int, multiset<int>>> nodesmap;
        
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
           auto p = q.front();
            q.pop();
            
            TreeNode * node = p.first;
            
            int x = p.second.first;
            int y = p.second.second;
            nodesmap[x][y].insert(node->val);
            
            if(node->left)
                q.push({node->left, {x-1, y+1}});
            
            if(node->right)
                q.push({node->right, {x+1, y+1}});
            
            
            
        }
        
        for(auto it: nodesmap){
                vector<int> col;
                for(auto i: it.second){
                    col.insert(col.end(),
                               i.second.begin(),
                              i.second.end());
                    
                    
                }
                
                ans.push_back(col);
            }
        
        return ans;
    }
};