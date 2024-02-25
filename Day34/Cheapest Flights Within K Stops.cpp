class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize distances for all nodes to infinity
        vector<int> distance(n, INT_MAX);

        // Create an adjacency list to store the graph
        unordered_map<int, vector<pair<int, int>>> adj;

        // Populate the adjacency list with the given flights data
        for (vector<int> &vec : flights) {
            int source = vec[0];
            int destination = vec[1];
            int cost = vec[2];

            adj[source].push_back({destination, cost});
        }

        // Initialize a queue to perform BFS traversal
        queue<pair<int, int>> qu;
        // Push the source node along with its distance (which is 0) into the queue
        qu.push({src, 0});
        // Distance from source to source is 0
        distance[src] = 0;

        int steps = 0;
        // Perform BFS traversal with a limit on number of steps (k)
        while (!qu.empty() && steps <= k) {
            // Get the number of nodes at the current level
            int Nodes = qu.size();
            // Process all nodes at the current level
            while (Nodes--) {
                // Get the node and its distance from the front of the queue
                pair<int, int> data = qu.front();
                int source = data.first;
                int cost = data.second;

                qu.pop(); // Remove the node from the queue

                // Explore all neighbors of the current node
                for (pair<int, int> &x : adj[source]) {
                    int s = x.first; // Neighbor node
                    int d = x.second; // Cost from current node to neighbor

                    // Update the distance if a shorter path is found
                    if (distance[s] > cost + d) {
                        distance[s] = d + cost;
                        // Push the neighbor node along with the updated distance into the queue
                        qu.push({s, d + cost});
                    }
                }
            }
            steps++; // Increment the steps counter
        }

        // Return the minimum distance to the destination node,
        // or -1 if there is no valid path
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
