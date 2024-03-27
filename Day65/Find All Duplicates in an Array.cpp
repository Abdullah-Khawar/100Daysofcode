class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        // Vector for storing duplicates
        vector<int> ans;
        
        // Iterate through each element in the input vector
        for(int i = 0; i < n; i++){
            // Get the absolute value of the current number
            int num = abs(nums[i]);
            
            // Calculate the index corresponding to the number
            int idx = num-1;

            // Check if the number at calculated index is negative
            // If negative, it means this number has been encountered before
            if(nums[idx] < 0){
                // If the number is already negative, it means it has been encountered before
                // Add this number to the list of duplicates
                ans.push_back(num);
            }
            else{
                // If the number is not negative, mark it as encountered by negating it
                nums[idx] *= -1;
            }
        }

        // Return the list of duplicates found
        return ans;
    }
};
