class Solution {
public:
    // Function to check if there are duplicates between two strings
    bool hasDuplicate(string &s1, string &s2) {
        int charCount[26] = {0};

        // Check for duplicates in the first string
        for (auto &ch : s1) {
            if (charCount[ch - 'a'] > 0) {
                return true;
            }
            charCount[ch - 'a']++;
        }

        // Check for duplicates in the second string
        for (auto &ch : s2) {
            if (charCount[ch - 'a'] > 0) {
                return true;
            }
        }

        return false;
    }

    // Recursive function to find the maximum length of a concatenation of strings without duplicates
    int maxLengthWithoutDuplicates(vector<string>& count, string temp, int currentIndex, int totalCount) {
        // Base case: If we reach the end of the array, return the length of the current concatenation
        if (currentIndex >= totalCount) {
            return temp.length();
        }

        int exclude = 0;
        int include = 0;

        // Check if adding the current string creates duplicates
        if (hasDuplicate(count[currentIndex], temp)) {
            exclude = maxLengthWithoutDuplicates(count, temp, currentIndex + 1, totalCount);
        } else {
            // If no duplicates, calculate both excluding and including the current string
            exclude = maxLengthWithoutDuplicates(count, temp, currentIndex + 1, totalCount);
            include = maxLengthWithoutDuplicates(count, temp + count[currentIndex], currentIndex + 1, totalCount);
        }

        // Return the maximum length between excluding and including the current string
        return max(include, exclude);
    }

    // Main function to calculate the maximum length of a concatenation of strings without duplicates
    int maxLength(vector<string>& arr) {
        int totalCount = arr.size();
        string temp = "";
        int currentIndex = 0;

        return maxLengthWithoutDuplicates(arr, temp, currentIndex, totalCount);
    }
};
