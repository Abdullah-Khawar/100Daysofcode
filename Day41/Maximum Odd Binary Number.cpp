class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();

        string res = string(n, '0');

        int cnt_1 = count(s.begin(), s.end(), '1');

        int i = 0;

        while (cnt_1 > 1) {
            res[i] = '1';
            i++;
            cnt_1--;
        }

        res[n - 1] = '1';

        return res;
    }
};
