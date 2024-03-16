class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Create an unordered_map to store the frequency of each cumulative sum
        unordered_map<int, int> mp;
        int currSum = 0; // Initialize the current sum
        mp[0] = 1; 
        int ans = 0; // Initialize the answer

        // Iterate through the elements of the input vector
        for (auto &num : nums) {
            currSum += num; // Update the current sum
            int remainingSum = currSum - goal; // Calculate the remaining sum needed to reach the goal
            ans += mp[remainingSum]; // Increment the answer by the frequency of the remaining sum
            mp[currSum]++; // Increment the frequency of the current sum in the map
        } 
        
        return ans; // Return the final answer
    }
};
