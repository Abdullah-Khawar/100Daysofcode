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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i)
        fast = fast->next;

    // If fast becomes NULL, it means we need to remove the head node
    if (fast == nullptr)
        return head->next;

    // Move both pointers until fast reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Now slow is pointing to the node just before the one to be deleted
    ListNode* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode; // Free the memory of the deleted node
    return head;
}
};
