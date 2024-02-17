class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        long long prmtr = -1;
        long long prevSum = 0;

        for (int i = 0; i < n; i++) {
            if (prevSum > nums[i]) {
                prmtr = prevSum + nums[i];
            }
            prevSum += nums[i];
        }

        return prmtr;
    }
};
