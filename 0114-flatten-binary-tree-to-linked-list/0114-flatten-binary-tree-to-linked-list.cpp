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

    void preorder(TreeNode* root, vector<TreeNode*> &ans){

        if(!root) return;

        ans.push_back(root);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:

    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root, ans);
        int n = ans.size();
        
    
        for(int i = 0; i < n-1; i++){
            ans[i]->left = nullptr;
            ans[i]->right = ans[i+1];
        }
        
        if(n>0){
            ans[n-1]->left = nullptr;
            ans[n-1]->right = nullptr;
        }
    }
};