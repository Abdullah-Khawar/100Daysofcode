class Solution {
public:
    int M = 1e9 + 7;
    int dp[50][50][51]; 

    int solve(int m, int n, int startRow, int startColumn, int maxMove) {
        // Base case: If the current position is outside the grid, return 1
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) {
            return 1;
        }

        // Base case: If maximum moves becomes 0, return 0
        if (maxMove <= 0) {
            return 0;
        }

        // If the result for the current state is already computed, return it
        if (dp[startRow][startColumn][maxMove] != -1) {
            return dp[startRow][startColumn][maxMove];
        }

        // Recursive calls in four possible directions, considering modulo M
        long long a = solve(m, n, startRow + 1, startColumn, maxMove - 1) % M;
        long long b = solve(m, n, startRow, startColumn + 1, maxMove - 1) % M;
        long long c = solve(m, n, startRow - 1, startColumn, maxMove - 1) % M;
        long long d = solve(m, n, startRow, startColumn - 1, maxMove - 1) % M;

        // Save the result in the memoization table and return the sum of the four directions
        return dp[startRow][startColumn][maxMove] = (a + b + c + d) % M;
    }

   
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));  // Initialize memoization table with -1
        return solve(m, n, startRow, startColumn, maxMove);
    }
};
