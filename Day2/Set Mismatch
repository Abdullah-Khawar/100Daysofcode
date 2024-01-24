class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;

        // Traverse the array to find the duplicate number
        for(int i = 0; i < n; i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                // If the element is already negative, it means we have encountered it before
                // and it is the duplicate
                dup = abs(nums[i]);
            } else {
                // Mark the element as visited by making it negative
                nums[abs(nums[i]) - 1] *= (-1);
            }
        }

        int missing = -1;

        // Traverse the array again to find the missing number
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                // If the element is positive, it means it was not visited during the first traversal
                // and it is the missing number
                missing = i + 1;
                break;
            }
        }

        return {dup, missing};
    }
};
