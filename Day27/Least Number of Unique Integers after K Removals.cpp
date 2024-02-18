class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Step 1: Count the occurrences of each integer in the array
        unordered_map<int, int> mp;
        for(auto &x: arr) mp[x]++;

        // Step 2: Create a multimap to sort integers by their occurrence counts
        multimap<int, int> mm;
        for(auto &y: mp) mm.insert({y.second, y.first});

        int cnt = 0; // Counter to keep track of the number of removed integers
        // Step 3: Iterate through the multimap, starting from integers with the lowest occurrence counts
        for(auto &z: mm){
            k -= z.first; // Subtract the occurrence count from 'k'
            // If 'k' becomes less than 0, we've removed more integers than allowed
            if(k < 0) 
            return mm.size() - cnt; // Return the remaining number of unique integers
            cnt++; // Increment the counter to keep track of the removed integers
        }

        return 0; 
    }
};
