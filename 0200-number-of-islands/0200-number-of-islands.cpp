class Solution {

private: 
    void bfs(int row, int col, vector<vector<char>>& grid ,vector<vector<char>>& vis){

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = '1';

        while(!q.empty()){
            pair<int, int> n = q.front();
            int Row = n.first;
            int Col = n.second;
            q.pop();

            if (Row-1 >= 0 && grid[Row-1][Col] == '1' && vis[Row-1][Col] != '1') {
                vis[Row-1][Col] = '1';
                q.push({Row-1, Col});
            }

            if (Row+1 < grid.size() && grid[Row+1][Col] == '1' && vis[Row+1][Col] != '1') {
                vis[Row+1][Col] = '1';
                q.push({Row+1, Col});
            }

            if (Col-1 >= 0 && grid[Row][Col-1] == '1' && vis[Row][Col-1] != '1') {
                vis[Row][Col-1] = '1';
                q.push({Row, Col-1});
            }

            if (Col+1 < grid[0].size() && grid[Row][Col+1] == '1' && vis[Row][Col+1] != '1') {
                vis[Row][Col+1] = '1';
                q.push({Row, Col+1});
            }
            
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<char>> vis(n, vector<char>(m, 0));
        int cnt = 0;
        

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){

                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt ++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};