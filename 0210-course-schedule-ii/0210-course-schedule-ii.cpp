class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        
        vector<vector<int>> adj(n);

        for(auto it : prerequisites){
            int course = it[0];
            int pre = it[1];

            adj[pre].push_back(course);
        }

        for(int i = 0; i < n ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0 ; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            result.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        for(int i = 0; i<n; i++){
            if(indegree[i] != 0) return {};
        }
        return result;
    }
};