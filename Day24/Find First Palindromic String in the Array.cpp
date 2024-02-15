class Solution {
public:
    bool checkPalindrom(string s){
        int n = s.size();
        if(n == 1) return true;
        int i = 0; 
        int j = n - 1;

        while(i <= j){
            if(s[i] != s[j]){
                return false;
                break;
            }
            i++;
            j--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {
            int n = words.size();
            
            for(auto &st: words){
                if(checkPalindrom(st)){
                    return st;
                    break;
                }
            }

            return "";
    }   
};
