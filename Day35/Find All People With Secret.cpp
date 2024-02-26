class Solution {
public:
    using P = pair<int, int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // Step 1: Initialize a map to store meetings happening at each time
        map<int, vector<P>> timeMeetings;

        // Step 2: Populate the map with meetings
        for (auto& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            timeMeetings[time].push_back({person1, person2});
        }

        // Step 3: Vector to track if each person knows the secret
        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true; // First person knows the secret initially
        knowsSecret[firstPerson] =
            true; // Given first person also knows the secret

        // Step 4: Traverse through meetings to update who knows the secret
        for (auto& it : timeMeetings) {
            int time = it.first;
            vector<P> meet = it.second;

            // Step 5: Adjacency list to represent who met whom
            unordered_map<int, vector<int>> adj;
            queue<int> q; // Queue for BFS traversal
            unordered_set<int>
                alreadyAdded; // To avoid adding duplicate persons to the queue

            // Step 6: Populate adjacency list and initialize BFS traversal
            // queue
            for (auto& [person1, person2] : meet) {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                // If the person knows the secret and not already added to the
                // queue, add to queue
                if (knowsSecret[person1] &&
                    alreadyAdded.find(person1) == alreadyAdded.end()) {
                    q.push(person1);
                    alreadyAdded.insert(person1);
                }
                if (knowsSecret[person2] &&
                    alreadyAdded.find(person2) == alreadyAdded.end()) {
                    q.push(person2);
                    alreadyAdded.insert(person2);
                }
            }

            // Step 7: Perform BFS traversal to update who knows the secret
            while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (auto& nextPerson : adj[person]) {
                    if (!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson); // Add newly known person to the
                                            // queue for further traversal
                    }
                }
            }
        }

        // Step 8: Collect indices of people who eventually know the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowsSecret[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
