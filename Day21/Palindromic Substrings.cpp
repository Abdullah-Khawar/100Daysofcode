class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); 
        
        // Create a 2D vector to store information about palindromic substrings
        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = 0; // Initialize the count of palindromic substrings
        
        // Iterate through all possible lengths of substrings
        for(int L = 1; L <= n; L++){
            // Iterate through all possible starting indices of substrings
            for(int i = 0; i <= n - L; i++){
                int j = i + L - 1; // Calculate the ending index of the substring

                // Check if the current substring is a palindrome
                if(L == 1) {
                    t[i][j] = true; // Substring of length 1 is always a palindrome
                } else if(L == 2 && s[i] == s[j]) {
                    t[i][j] = true; // Substring of length 2 is a palindrome if its characters are the same
                } else if(s[i] == s[j] && t[i+1][j-1]) {
                    t[i][j] = true; // For longer substrings, check if the inner substring is a palindrome
                }

                if(t[i][j]) count++; // If the substring is a palindrome, increment the count
            }
        }    

        return count; // Return the total count of palindromic substrings
    }
};
