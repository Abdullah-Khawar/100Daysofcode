class Solution {
public:
    
    int M = 1e9 + 7;
    int dp[1001][1001];

    // Recursive function to calculate the number of arrays with k inverse pairs
    int solve(int n, int k){
        // Base case: if the length of the array is 0, there is only 1 way (empty array)
        if(n == 0) return 0;

        // Base case: if the number of inverse pairs is 0, there is only 1 way (sorted array)
        if(k == 0) return 1;

        // If the result for the current subproblem is already calculated, return it
        if(dp[n][k] != -1) return dp[n][k];

        // Initialize the result for the current subproblem
        int result = 0;

        // Iterate through the possible number of inverse pairs for the current element.
        for(int inv = 0; inv <= min(k, n-1); inv++){
            // Recursively calculate the number of arrays with the remaining elements.
            result = (result + solve(n - 1, k - inv)) % M;
        }

        // Memoize the result and return it
        return dp[n][k] = result;
    }


    int kInversePairs(int n, int k) {
        // Initialize the dp array with -1
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};
