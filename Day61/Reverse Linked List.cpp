class Solution {
public:
    // Function to reverse a singly-linked list
    ListNode* reverseList(ListNode* head) {
        // If the list is empty or has only one node, return the head as it is already reversed
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* curr = head;  // Pointer to the current node
        ListNode* prev = NULL;  // Pointer to the previous node, initialized to NULL as it's the end of the reversed list
        ListNode* forward = NULL;  // Pointer to the next node to be processed

        // Traverse the list and reverse pointers
        while (curr != NULL) {
            forward = curr->next;  // Store the next node to prevent loss of connection
            curr->next = prev;     // Reverse the pointer to point to the previous node

            prev = curr;  // Move prev to current position
            curr = forward;  // Move curr to the next node
        }

        return prev;  // 'prev' now points to the new head of the reversed list
    }
};
