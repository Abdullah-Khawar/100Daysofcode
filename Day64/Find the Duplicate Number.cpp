class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize two pointers, slow and fast, both starting at the first element of the vector
        int slow = nums[0];
        int fast = nums[0];

        // Move slow one step and fast two steps
        slow = nums[slow];
        fast = nums[nums[fast]];

        // Move until they meet in a cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Reset one pointer to the start and move both pointers one step at a time until they meet
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // When they meet again, it indicates the start of the cycle which is the duplicate number
        return slow;
    }
};
