class Solution {
public:
    int n, m;
    int dp[71][71][71];

    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        // Base case
        if (row >= m) return 0;

        // Cherry calculation 
        int cherry = grid[row][c1];
        if (c1 != c2) cherry += grid[row][c2]; // Cherry from two different cells
        
        // Checking existing solution
        if (dp[row][c1][c2] != -1) return dp[row][c1][c2];

        int ans = 0;
        // Recursive call for all the possibilities
        for (int i = -1; i <= 1; i++) { // Robot-1
            for (int j = -1; j <= 1; j++) { // Robot-2
                
                int newRow = row + 1;
                int newC1 = c1 + i;
                int newC2 = c2 + j;

                // Out of bound condition check
                if (newC1 >= 0 && newC1 < n && newC2 >= 0 && newC2 < n)
                    ans = max(ans, solve(grid, newRow, newC1, newC2));
            }        
        }
        return dp[row][c1][c2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(); // Number of columns
        n = grid[0].size(); // Number of rows

        memset(dp, -1, sizeof(dp)); // Initializing dp array with -1

        return solve(grid, 0, 0, n - 1); // Starting with robots at the first and last columns
    }
};
