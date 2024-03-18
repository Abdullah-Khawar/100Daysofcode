class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        // HashMap to store cumulative sum and its corresponding index
        unordered_map<int, int> mp;
        // Initialize the hashmap with initial sum 0 at index -1
        mp[0] = -1;

        int currSum = 0; // Initialize current sum
        int maxLength = 0; // Initialize maximum length of subarray
        for(int i = 0; i < n; i++){
            // Increment current sum by 1 if nums[i] is 1, otherwise decrement by 1
            // Note --> We are replacing 0's with -1 in the array
            currSum += (nums[i] == 1) ? 1 : -1;

            // Check if the current sum exists in the hashmap
            if(mp.find(currSum) != mp.end()){
                // If exists, update maxLength if the length of current subarray is greater
                maxLength = max(maxLength, i - mp[currSum]);
            }
            else {
                // If not exists, add current sum to the hashmap with its index
                mp[currSum] = i;
            }
        }

        return maxLength; // Return the maximum length of subarray with equal 0s and 1s
    }
};
