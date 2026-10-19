
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        int max_time = 0;

        queue<pair<int, pair<int, int>>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, {j, 0}});
                }
                else if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        while(!q.empty()) {
            pair<int, pair<int, int>> cur = q.front();

            int r = cur.first;
            int c = cur.second.first;
            int t = cur.second.second;

            q.pop();

            max_time = max(max_time, t);

            // Up
            if(r - 1 >= 0 && grid[r - 1][c] == 1) {
                grid[r - 1][c] = 2;
                count--;
                q.push({r - 1, {c, t + 1}});
            }

            // Down
            if(r + 1 < n && grid[r + 1][c] == 1) {
                grid[r + 1][c] = 2;
                count--;
                q.push({r + 1, {c, t + 1}});
            }

            // Right
            if(c + 1 < m && grid[r][c + 1] == 1) {
                grid[r][c + 1] = 2;
                count--;
                q.push({r, {c + 1, t + 1}});
            }

            // Left
            if(c - 1 >= 0 && grid[r][c - 1] == 1) {
                grid[r][c - 1] = 2;
                count--;
                q.push({r, {c - 1, t + 1}});
            }
        }

        if(count > 0) {
            return -1;
        }

        return max_time;
    }
};

