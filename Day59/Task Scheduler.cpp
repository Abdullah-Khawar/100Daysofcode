class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Initialize a map to store frequencies of each task
        vector<int> mp(26, 0); // Assuming only uppercase English letters are tasks
        
        // Populate the frequency map
        for(auto &ch: tasks){
            mp[ch - 'A']++; // Convert character to index and increment frequency
        }

        // Initialize a max heap to store frequencies in descending order
        priority_queue<int> pq;

        // Populate the priority queue with frequencies greater than 0
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0) pq.push(mp[i]);
        }

        int time = 0; // Initialize time counter

        // Continue until the priority queue is empty
        while(!pq.empty()){
            
            vector<int> temp; // Temporary vector to store frequencies of tasks being executed

            // Execute tasks for n+1 cycles
            for(int i = 1;  i <= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top(); // Get the task with highest frequency
                    pq.pop(); // Remove the task from the priority queue
                    freq--; // Decrement its frequency
                    temp.push_back(freq); // Store the decremented frequency
                }
            }

            // Push back frequencies from temporary vector to priority queue if they are greater than 0
            for(auto &freq: temp){
                if(freq > 0) pq.push(freq);
            }

            // Increment time based on the current cycle
            if(!pq.empty()){
                time += n+1; // If there are tasks left, increment time by cooling time
            }
            else{
                time += temp.size(); // If no tasks left, increment time by the number of tasks executed
            }
        }

        return time; // Return the total time taken
    }
};
