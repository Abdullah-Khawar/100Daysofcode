/**
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a hash map to store prefix sums and their corresponding nodes
        unordered_map<int, ListNode*> mp;

        int prefixSum = 0;

        // Create a dummy node to handle cases where the entire list sums to zero
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy; // Initialize map with prefix sum 0 and dummy node

        // Traverse the list
        while(head != NULL){
            prefixSum += head->val; // Calculate prefix sum
        
            if(mp.find(prefixSum) != mp.end()){ // If prefix sum already exists in map
                ListNode* start = mp[prefixSum]; // Get the node corresponding to the start of the sublist with the same prefix sum

                ListNode* temp = start;
                int pSum = prefixSum;

                // Iterate from the start node to the current node to remove the sublist with zero sum
                while(temp != head){
                    temp = temp-> next; // Move temp to the next node
                    pSum += temp-> val; // Update prefix sum
                    
                    if(temp != head){
                        mp.erase(pSum); // Remove prefix sum from map if it's not the last node in the sublist
                    }
                }
              
                start-> next = head-> next; // Remove sublist by adjusting the pointers
            }
            else{
                mp[prefixSum] = head; // Store prefix sum and its corresponding node in map
            }

            head = head->next; // Move to the next node in the list
        }
        
        // Return the modified list
        return dummy-> next;
    }
};
