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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> ans;
        inorder(root, ans);

        
        int output;

        for(int i = 0; i<k; i++){
            output = ans[i]->val;
        }
        return output;
    }


void inorder(TreeNode* root, vector<TreeNode*>& ans) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root);
    inorder(root->right, ans);
}
};