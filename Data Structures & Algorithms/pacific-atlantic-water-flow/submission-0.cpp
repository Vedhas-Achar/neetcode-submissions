class Solution {
public:

    int m, n;
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int r, int c) {
        vis[r][c] = true;

        for(auto d: dir){
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

            if(vis[nr][nc]) continue;

            if(heights[nr][nc] < heights[r][c]) continue;

            dfs(heights, vis, nr, nc);
        }


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<bool>(n, false));
        atlantic.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0);

        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j);

        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1);

        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;

    }
};
