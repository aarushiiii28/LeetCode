
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        int max_time = 0;

        queue<pair<int, pair<int, int>>> q;

        // Count fresh oranges and push rotten oranges into the queue
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

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            pair<int, pair<int, int>> cur = q.front();

            int i = cur.first;
            int j = cur.second.first;
            int t = cur.second.second;

            q.pop();

            max_time = max(max_time, t);

            for(int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];

                if(r >= 0 && r < n &&
                   c >= 0 && c < m &&
                   grid[r][c] == 1) {

                    grid[r][c] = 2;
                    count--;

                    q.push({r, {c, t + 1}});
                }
            }
        }

        if(count > 0) {
            return -1;
        }

        return max_time;
    }
};

