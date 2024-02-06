class Solution {
public:
    string minWindow(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        if(l2 > l1) return "";

        unordered_map<char, int> mp;
        int requiredCount = l2;

        for(int i = 0; i < l2; i++) mp[t[i]]++;
        int i = 0;
        int j = 0;

        int minWindowSize = INT_MAX;
        int start_i = 0;
        while(j < l1){

            char ch = s[j];

            if(mp[ch] > 0) requiredCount--;

            mp[ch]--;          

            while(requiredCount == 0){
                int currentWindowSize = j-i+1;

                if(minWindowSize > currentWindowSize){
                   minWindowSize = currentWindowSize;
                   start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0) requiredCount++; 

                i++;
            }

        j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);

    }
};
