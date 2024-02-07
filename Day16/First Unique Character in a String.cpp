class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();

        int index = -1;

        unordered_map <char, int> mp;
 
        for(auto &it: s) mp[it]++;
        
        for(int i = 0; i < n; i++){
           if(mp[s[i]] == 1) 
           {index = i;
           break;
           }
        }

  return index;

    }
};
