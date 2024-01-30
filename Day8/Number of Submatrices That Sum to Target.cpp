class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int result = 0;

        // Cumulative sum for each column
        for (int rows = 0; rows < row; rows++) {
            for (int cols = 1; cols < col; cols++) {
                matrix[rows][cols] += matrix[rows][cols - 1];
            }
        }

        // Iterate over all possible submatrices
        for (int startCol = 0; startCol < col; startCol++) {
            for (int j = startCol; j < col; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int preSum = 0;

                // Iterate over rows
                for (int rows = 0; rows < row; rows++) {
                    // Update cumulative sum for the current column range
                    matrix[rows][j] -= (startCol > 0 ? matrix[rows][startCol - 1] : 0);
                    preSum += matrix[rows][j];

                    // Check if there is a submatrix with sum equal to target
                    int remaining = preSum - target;
                    result += mp[remaining];

                    // Update the frequency of the current cumulative sum
                    mp[preSum]++;
                }
            }
        }
        return result;
    }
};
