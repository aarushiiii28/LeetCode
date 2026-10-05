/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        vector<vector<TreeNode*>> ans = levelOrder(root);

        string s = "";

        for (auto level : ans) {
            for (auto node : level) {

                if (node == NULL) {
                    s += "#,";
                }
                else {
                    s += to_string(node->val) + ",";
                }
            }
        }

        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.empty())
            return NULL;

        // Store nodes in level-order
        vector<TreeNode*> nodes;

        string temp = "";

        for (int i = 0; i < data.size(); i++) {

            if (data[i] == ',') {

                if (temp == "#") {
                    nodes.push_back(NULL);
                }
                else {
                    nodes.push_back(new TreeNode(stoi(temp)));
                }

                temp = "";
            }
            else {
                temp += data[i];
            }
        }

        if (nodes.empty() || nodes[0] == NULL)
            return NULL;

        // First node is root
        TreeNode* root = nodes[0];

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        // Reconstruct tree using level order
        while (!q.empty() && i < nodes.size()) {

            TreeNode* curr = q.front();
            q.pop();

            // Left child
            curr->left = nodes[i++];

            if (curr->left != NULL)
                q.push(curr->left);

            // Right child
            if (i < nodes.size()) {

                curr->right = nodes[i++];

                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }

        return root;
    }


    // Level order traversal including NULL positions
    vector<vector<TreeNode*>> levelOrder(TreeNode* root) {

        vector<vector<TreeNode*>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();

            vector<TreeNode*> level;

            bool hasNonNull = false;

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node == NULL) {

                    level.push_back(NULL);
                    continue;
                }

                hasNonNull = true;

                level.push_back(node);

                q.push(node->left);
                q.push(node->right);
            }

            // Don't add the final level containing only NULLs
            if (hasNonNull) {
                ans.push_back(level);
            }
            else {
                break;
            }
        }

        return ans;
    }
};