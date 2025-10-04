class Solution {
public:
    int n, m;
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp; 
    int f(int i, int j, int move, vector<vector<int>>& grid){
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j][move] != -1) return dp[i][j][move];

        int right = 0;
        int down = 0;
        if(grid[i][j] == 1){
            if(move == 1){
                down = f(i+1, j, 0, grid);
            }
            else if(move == 0){
                right = f(i, j+1, 1, grid);
            }
        }
        else{
            right = f(i, j+1, 1, grid);
            down = f(i+1, j, 0, grid);
        }

        return dp[i][j][move] = (right + down) % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return f(0, 0, 0, grid);
    }
};