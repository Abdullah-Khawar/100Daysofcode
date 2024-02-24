class Solution {
public: 
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);

        for (auto &trst : trust) {
            int personA = trst[0];
            int personB = trst[1];
            trustCount[personA]--; // Decrease trust count for personA
            trustCount[personB]++; // Increase trust count for personB
        }

        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) { // Check if a person is trusted by everyone else
                return i; // Return the judge
            }
        }

        return -1; // No judge found
    }
};
