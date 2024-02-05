class Solution {
public:
    int n;
    int dp[501];

    int solve(int i, vector<int>& arr, int k) {
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int maxi = -1;
        int result = 0;

        for (int j = i; (j < n) && ((j - i + 1) <= k); j++) {
            maxi = max(maxi, arr[j]);
            result = max(result, (j - i + 1) * maxi + solve(j + 1, arr, k));
        }

        return dp[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};
