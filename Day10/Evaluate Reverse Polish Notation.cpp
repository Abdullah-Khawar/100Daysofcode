class Solution {
public:
    int operater(int a, int b, string token) {
        if (token == "+")
            return a + b;
        if (token == "-")
            return a - b;
        if (token == "*")
            return (long long)a * (long long)b;
        if (token == "/")
            return a / b;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& token : tokens) {

            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = operater(a, b, token);

                st.push(result);
            }

            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
