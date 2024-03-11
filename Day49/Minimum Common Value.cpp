class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // Initialize pointers for both arrays
        int i = 0;
        int j = 0;
        
        // Get sizes of both arrays
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Iterate through both arrays until one is exhausted
        while(i < n1 && j < n2) {
            // If current elements in both arrays are equal, return the common element
            if(nums1[i] == nums2[j]) {
                return nums1[i]; // Common element found, return and exit
            }
            // If current element in nums1 is less than current element in nums2, move to next element in nums1
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            // If current element in nums2 is less than current element in nums1, move to next element in nums2
            else {
                j++;
            }
        }
        
        // If no common element is found, return -1
        return -1;
    }
};
