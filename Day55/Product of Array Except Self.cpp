class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Initialize a result vector with all elements set to 1
        vector<int> result(n, 1);

        int prefix = 1; // Variable to store the product of elements before the current index
        int suffix = 1; // Variable to store the product of elements after the current index

        // Compute the products of elements before each index and store in the result vector
        for (int i = 0; i < n; i++) {
            result[i] *= prefix; // Update result[i] with product of elements before i
            prefix *= nums[i]; // Update prefix with product of elements encountered so far
        }
 
        // Compute the products of elements after each index and update the result vector
        for (int j = n-1; j >= 0; j--) {
            result[j] *= suffix; // Update result[j] with product of elements after j
            suffix *= nums[j]; // Update suffix with product of elements encountered so far
        }

        return result; // Return the result vector containing the product of all elements except self
    }
};
