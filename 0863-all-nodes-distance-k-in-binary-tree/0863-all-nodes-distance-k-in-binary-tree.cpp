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

    void make_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        
        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        make_parent(root, parent_track);


        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;
        int dis = 0;

        while(!q.empty()){

            if(dis++ == k) break;
            int n = q.size();
            
            for(int i = 0; i<n; i++){

                TreeNode* current = q.front();
                q.pop();
                
                if(current->left && vis[current->left] == false){
                    q.push(current->left);
                    vis[current->left] = true;
                }
                if(current->right && vis[current->right] == false){
                    q.push(current->right);
                    vis[current->right] = true;
                }
                if(parent_track[current] && vis[parent_track[current]] == false){
                    q.push(parent_track[current]);
                    vis[parent_track[current]] = true;
                }
            }
        }           
        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
            
        }
        return result;
    }
};