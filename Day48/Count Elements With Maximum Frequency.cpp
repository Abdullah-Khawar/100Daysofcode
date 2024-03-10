class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Create a hash map to store the frequency of each number
        unordered_map<int, int> mp;

        // Count the frequency of each number in the input vector
        for (auto& num : nums) {
            mp[num]++;
        }
        
        // Find the maximum frequency among all numbers
        int maxFrequency = 0;
        for (auto& it : mp) {
            if (it.second > maxFrequency) {
                maxFrequency = it.second;
            }
        }

        // Count how many numbers have the maximum frequency
        int numOccurence = 0;
        for (auto& it : mp) {
            if (it.second == maxFrequency) {
                numOccurence++;
            }
        }

        // Multiply the maximum frequency by the number of occurrences of numbers with that frequency
        return numOccurence * maxFrequency;
    }
};
