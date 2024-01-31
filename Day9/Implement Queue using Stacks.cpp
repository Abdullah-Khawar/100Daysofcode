class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    int peakElement = -1;

    MyQueue() {}

    void push(int x) {
        if (input.empty()) {
            peakElement = x;
        }
        input.push(x);
    }

    int pop() {
        if (output.empty()) {

            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int pop_var = output.top();
        output.pop();
        return pop_var;
    }

    int peek() {
        if (output.empty()) return peakElement;
        return output.top();
    }

    bool empty() {
        if (input.empty() && output.empty()) return true;
        return false;
    }
};
