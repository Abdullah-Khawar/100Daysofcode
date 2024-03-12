class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes 
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Vector to store the intersection elements
        vector<int> ans;

        // Sorting both input vectors
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Pointers to traverse both arrays
        int i = 0;
        int j = 0;
        
        // Loop until one of the arrays is fully traversed
        while (i < n1 && j < n2) {

            // If the elements at current positions are equal, it's an intersection
            if ((nums1[i] == nums2[j])) {
                // Add the element to the result
                ans.push_back(nums1[i]);
                // Move to the next different element in both arrays
                while (i < n1-1 && nums1[i] == nums1[i + 1])
                    i++;
                while (j < n2-1 && nums2[j] == nums2[j + 1])
                    j++;
                // Move pointers to next elements
                i++;
                j++;

            // If element in nums1 is smaller, move its pointer forward
            } else if (nums1[i] < nums2[j])
                i++;
            // If element in nums2 is smaller, move its pointer forward
            else
                j++;
        }
        // Return the vector containing intersection elements
        return ans;
    }
};
