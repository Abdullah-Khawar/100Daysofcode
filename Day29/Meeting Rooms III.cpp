class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        // Sort meetings based on start time
        sort(begin(meetings), end(meetings));

        // Vector to keep track of room usage count
        vector<int> roomUsedCount(n, 0);

        // Min heap to keep track of used rooms (sorted by end time)
        priority_queue<P, vector<P>, greater<P>> usedRooms;

        // Min heap to keep track of available rooms (sorted by room number)
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        // Initialize available rooms
        for (int room = 0; room < n; room++) {
            availableRooms.push(room);
        }

        for (vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            // Free up rooms whose meetings have ended
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            if (!availableRooms.empty()) {
                // If there are available rooms, assign the meeting to the room with the smallest room number
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({ end, room });
                roomUsedCount[room]++;
            } else {
                // All rooms are busy, assign the meeting to the room with the earliest available time
                int room = usedRooms.top().second;
                long long endMeetingTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({ endMeetingTime + duration, room });
                roomUsedCount[room]++;
            }
        }

        // Find the room with the maximum usage count
        int roomUsedMaximumTimes = -1;
        int maxUse = 0;

        for (int room = 0; room < n; room++) {
            if (roomUsedCount[room] > maxUse) {
                maxUse = roomUsedCount[room];
                roomUsedMaximumTimes = room;
            }
        }

        return roomUsedMaximumTimes;
    }
};
