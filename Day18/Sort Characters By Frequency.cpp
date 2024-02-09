class Solution {
public:
    typedef pair<char, int> P;

    struct lamda {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s) {
        
        priority_queue <P, vector<P>, lamda> pq;

        unordered_map <char, int> mp;

        for(auto &x: s) mp[x]++;

        for(auto &x: mp) pq.push({x.first, x.second});

        string ans = ""; 
        P temp; 
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();

            ans += string(temp.second, temp.first);
        }

        return ans;

    }
};
