class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){

                if (vis[i][j] != 1 && grid[i][j] == 1 &&
                   (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                        bfs(i, j, vis, grid);
                }
                
            }
        }

        int cnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){

                if(vis[i][j] != 1 && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
    return cnt;
        
    }

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        while(!q.empty()){

            pair<int,int> cur = q.front();
            int r = cur.first;
            int c = cur.second;
            q.pop();

            // Up
            if (r-1 >= 0 && grid[r-1][c] == 1 && vis[r-1][c] != 1) {
                vis[r-1][c] = 1;
                q.push({r-1, c});
            }

            // Down
            if (r+1 < grid.size() && grid[r+1][c] == 1 && vis[r+1][c] != 1) {
                vis[r+1][c] = 1;
                q.push({r+1, c});
            }

            // Right
            if (c+1 < grid[0].size() && grid[r][c+1] == 1 && vis[r][c+1] != 1) {
                vis[r][c+1] = 1;
                q.push({r, c+1});
            }

            // Left
            if (c-1 >= 0 && grid[r][c-1] == 1 && vis[r][c-1] != 1) {
                vis[r][c-1] = 1;
                q.push({r, c-1});
            }
        }
    }

};