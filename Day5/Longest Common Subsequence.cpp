class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int j, string& s1, string& s2) {
        // Base Case: If either of the strings reaches the end, return 0
        if (i >= s1.length() || j >= s2.length())
            return 0;

        // If the result is already calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If the characters at the current positions are the same
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2);
        }

        // If the characters are different, try both possibilities and choose the maximum
        return dp[i][j] = max(solve(i, j + 1, s1, s2), solve(i + 1, j, s1, s2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        // Initialize the memoization array with -1
        memset(dp, -1, sizeof(dp));
    
        return solve(0, 0, text1, text2);
    }
};
