class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> qu;
        vector<int> ans;

        for(int i = 1; i <= 8; i++){
            qu.push(i);
        }

        while(!qu.empty()){
            int temp = qu.front();
            qu.pop();

            if(temp >= low && temp <= high){
                ans.push_back(temp);
            }

            int last_digit = temp % 10;
            if(last_digit + 1 <= 9){
                    qu.push(temp * 10 + (last_digit + 1));
            }

        }
return ans;
    }
};
