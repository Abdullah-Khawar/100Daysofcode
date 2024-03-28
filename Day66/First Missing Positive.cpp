class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); 

        // Rearrange the elements in nums such that nums[i] = i + 1 for each valid i.
        for (int i = 0; i < n; i++) {
            int element = nums[i]; // Current element being processed

            // If the current element is within the valid range [1, n]
            if (element >= 1 && element <= n) {
                int correctPosition = element - 1; // Calculate the correct position for the element

                // If the element is not already in its correct position
                if (nums[correctPosition] != element) {
                    // Swap the current element with the element at its correct position
                    swap(nums[correctPosition], nums[i]);
                    i--; // Decrement i to recheck the element which has been swapped
                }
            }
        }

        // Find the first missing positive integer in the rearranged nums array
        for (int i = 0; i < n; i++) {
            // If nums[i] != i + 1, then i + 1 is the first missing positive integer
            if (nums[i] != i + 1)
                return i + 1;
        }

        // If all integers from 1 to n are present, then the first missing positive integer is n + 1
        return n + 1;
    }
};
