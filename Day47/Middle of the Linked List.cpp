/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Function to find the middle node of a singly-linked list
    // Returns the middle node of the list
    ListNode* middleNode(ListNode* head) {
        // If the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // If the list has only two nodes, return the second node
        if (head->next->next == nullptr) {
            return head->next;
        }

        // Initialize slow and fast pointers
        ListNode* slow = head;  // Slow pointer moves one step at a time
        ListNode* fast = head->next;  // Fast pointer moves two steps at a time

        // Traverse the list until fast pointer reaches the end
        while (fast != nullptr) {
            fast = fast->next;  // Move fast pointer one step
            if (fast != nullptr) {
                fast = fast->next;  // Move fast pointer one more step
            }
            slow = slow->next;  // Move slow pointer one step
        }

        // At this point, slow pointer is at the middle of the list
        return slow;
    }
};
