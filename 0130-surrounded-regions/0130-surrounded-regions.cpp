class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){

                if (vis[i][j] != 1 && board[i][j] == 'O' &&
                   (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                        bfs(i, j, vis, board);
                }
                
            }
        }

        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){

                if(vis[i][j] != 1 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        while(!q.empty()){

            pair<int,int> cur = q.front();
            int r = cur.first;
            int c = cur.second;
            q.pop();

            // Up
            if (r-1 >= 0 && board[r-1][c] == 'O' && vis[r-1][c] != 1) {
                vis[r-1][c] = 1;
                q.push({r-1, c});
            }

            // Down
            if (r+1 < board.size() && board[r+1][c] == 'O' && vis[r+1][c] != 1) {
                vis[r+1][c] = 1;
                q.push({r+1, c});
            }

            // Right
            if (c+1 < board[0].size() && board[r][c+1] == 'O' && vis[r][c+1] != 1) {
                vis[r][c+1] = 1;
                q.push({r, c+1});
            }

            // Left
            if (c-1 >= 0 && board[r][c-1] == 'O' && vis[r][c-1] != 1) {
                vis[r][c-1] = 1;
                q.push({r, c-1});
            }
        }
    }
};