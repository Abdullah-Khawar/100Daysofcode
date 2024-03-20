class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(); // Number of balloons

        // Sort the balloons based on their start position
        sort(begin(points), end(points));

        int cnt = 1; // Counter for the number of arrows needed, initialized to 1 as at least one arrow is needed to cover the first balloon

        vector<int> prev = points[0]; // Initialize previous balloon's interval
        for (int i = 1; i < n; i++) {
            if (points[i][0] > prev[1]) { // If the current balloon's start position is after the end position of the previous balloon
                cnt++; // Increment the counter as a new arrow is needed to cover the current balloon
                prev = points[i]; // Update the previous balloon's interval
            } else { // If there is an overlap between the current balloon and the previous balloon
                // Update the interval covered by the arrow to minimize the range
                prev[0] = max(prev[0], points[i][0]); // Update the start position of the covered interval
                prev[1] = min(prev[1], points[i][1]); // Update the end position of the covered interval
            }
        }
        return cnt; // Return the total number of arrows needed
    }
};
