class Solution {
public:
    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int lh = 0;
        TreeNode* temp = root;

        while(temp) {
            lh++;
            temp = temp->left;
        }

        int rh = 0;
        temp = root;

        while(temp) {
            rh++;
            temp = temp->right;
        }

        // Perfect binary tree
        if(lh == rh) {
           return pow(2, lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};