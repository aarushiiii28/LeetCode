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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> inOrder;
        inorder(root, inOrder);
        bool check = true;

        for(int i = 0; i<inOrder.size()-1; i++){
            if(inOrder[i]->val < inOrder[i+1]->val){
                check = true;
            }
            else{
                check = false;
                break;
            }
        }
        return check;
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