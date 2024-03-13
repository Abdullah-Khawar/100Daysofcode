class Solution {
public:
    string customSortString(string order, string s) {
        // Create a vector to store the index of each character in the 'order' string
        vector<int> index(26, -1); //  Only lowercase letters are considered here
        
        // Populate the index vector with the indices of characters in 'order'
        for(int i = 0; i < order.length(); i++){
            char ch = order[i];
            index[ch - 'a'] = i; // Store the index of character 'ch' in the index vector
        }

        // Define a custom comparator function to sort characters based on their indices in 'order'
        auto mycomparator = [&index](char& ch1, char& ch2){
            // Compare the indices of ch1 and ch2 using the index vector
            return index[ch1 - 'a'] < index[ch2 - 'a'];
        };

        // Sort the string 's' using the custom comparator
        sort(begin(s), end(s), mycomparator);

        // Return the sorted string
        return s;
    }
};
