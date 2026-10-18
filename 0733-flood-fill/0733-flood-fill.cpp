class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));


        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        while(!q.empty()){
            pair<int,int> cur = q.front();
            int row = cur.first;
            int col = cur.second;
            q.pop();

            if (row-1 >= 0 && image[row-1][col] == originalColor && vis[row-1][col] != 1) {
                vis[row-1][col] = 1;
                image[row-1][col] = color;
                q.push({row-1, col});
            }

            if (row+1 < image.size() && image[row+1][col] == originalColor && vis[row+1][col] != 1) {
                vis[row+1][col] = 1;
                image[row+1][col] = color;
                q.push({row+1, col});
            }

            if (col-1 >= 0 && image[row][col-1] == originalColor && vis[row][col-1] != 1) {
                vis[row][col-1] = 1;
                image[row][col-1] = color;
                q.push({row, col-1});
            }

            if (col+1 < image[0].size() && image[row][col+1] == originalColor && vis[row][col+1] != 1) {
                vis[row][col+1] = 1;
                image[row][col+1] = color;
                q.push({row, col+1});
            }
        }
        return image;
    }

    
};