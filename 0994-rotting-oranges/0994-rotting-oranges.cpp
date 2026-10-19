class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        bfs(grid, vis, fresh, time, q);

        if (fresh > 0) {
            return -1;
        }

        return time;
    }

    void bfs(vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             int& fresh,
             int& time,
             queue<pair<int, int>>& q) {

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> cur = q.front();
                int r = cur.first;
                int c = cur.second;
                q.pop();

                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    vis[r - 1][c] = 1;
                    q.push({r - 1, c});
                    fresh--;
                }

                if (r + 1 < grid.size() && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    vis[r + 1][c] = 1;
                    q.push({r + 1, c});
                    fresh--;
                }

                if (c + 1 < grid[0].size() && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    vis[r][c + 1] = 1;
                    q.push({r, c + 1});
                    fresh--;
                }

                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    vis[r][c - 1] = 1;
                    q.push({r, c - 1});
                    fresh--;
                }
            }

            time++;
        }
    }
};