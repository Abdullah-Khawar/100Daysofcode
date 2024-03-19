class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Initialize a vector to store the merged intervals
        vector<vector<int>> ans;
        // Initialize an index variable
        int i = 0;
        
        // Iterate through the intervals
        while (i < intervals.size()) {
            // If the end of the current interval is before the start of the new interval
            if (intervals[i][1] < newInterval[0]) {
                // Add the current interval to the result
                ans.push_back(intervals[i]);
            }
            // If the start of the current interval is after the end of the new interval
            else if (intervals[i][0] > newInterval[1]) {
                // Break the loop as there's no need to continue further
                break;
            }
            else { 
                // If there is an overlap between the current interval and the new interval
                // Update the new interval to merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            // Move to the next interval
            i++;
        }

        // Add the merged interval to the result
        ans.push_back(newInterval);
        
        // Add any remaining intervals from the original list
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Return the merged intervals
        return ans;
    }
};
