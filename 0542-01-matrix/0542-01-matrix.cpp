class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));

        queue<pair<pair<int,int>, int>> q;
        
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j} , 0});
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto cur = q.front();

            auto r = cur.first.first;
            auto c = cur.first.second;
            auto t = cur.second;

            q.pop();

            // Up
            if(r - 1 >= 0 && vis[r - 1][c] != 1 ) {
                q.push({{r-1,c}, t+1});
                dis[r-1][c] = t+1;
                vis[r-1][c] = 1;
            }

            // Down
            if(r + 1 < n && vis[r + 1][c] != 1) {
                q.push({{r+1,c}, t+1});
                dis[r+1][c] = t+1;
                vis[r+1][c] = 1;
            }

            // Right
            if(c + 1 < m && vis[r][c + 1] != 1) {
                q.push({{r,c+1}, t+1});
                dis[r][c+1] = t+1;
                vis[r][c+1] = 1;
            }

            // Left
            if(c - 1 >= 0 && vis[r][c - 1] != 1) {
                q.push({{r,c-1}, t+1});
                dis[r][c-1] = t+1;
                vis[r][c-1] = 1;
            }
        }
    return dis;
    }
};