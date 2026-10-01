/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        
        nodeP(root, arr1, p);
        nodeQ(root, arr2, q);

        int n = arr1.size();
        int m = arr2.size();

        int i = 0;
        TreeNode* ans = nullptr;

        while(i<n && i<m && arr1[i] == arr2[i]){
            ans = arr1[i];
            i++;
        }
        return ans;
    }

    bool nodeP(TreeNode* root, vector<TreeNode*> &arr1, TreeNode* p){
        if(!root) return false;

        arr1.push_back(root);

        if(root == p){
            return true;
        }

        if(nodeP(root->left, arr1, p) || nodeP(root->right, arr1, p)) return true;

        arr1.pop_back();
        return false;
    }

    bool nodeQ(TreeNode* root, vector<TreeNode*> &arr2, TreeNode* q){
        if(!root) return false;

        arr2.push_back(root);

        if(root == q){
            return true;
        }

        if(nodeQ(root->left, arr2, q) || nodeQ(root->right, arr2, q)) return true;

        arr2.pop_back();
        return false;
    }


};