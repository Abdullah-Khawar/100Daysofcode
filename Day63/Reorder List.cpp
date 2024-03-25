class Solution {
public:
    // Function to find the middle node of the linked list
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        // Using slow and fast pointers to find the middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to reverse a linked list
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;

        // Reversing the linked list
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // Function to reorder the given linked list
    void reorderList(ListNode* head) {
        // Finding the middle node
        ListNode* mid = middle(head);
        
        // Reversing the second half of the linked list
        ListNode* rev = reverse(mid->next);
        
        // Cutting off the original list at the middle node
        mid->next = NULL;

        // Reordering the linked list by alternating nodes from both halves
        ListNode* curr = head;
        while(rev){
            ListNode* currTemp = curr->next;
            curr->next = rev;

            ListNode* revTemp = rev->next;
            rev->next = currTemp;

            curr = currTemp;
            rev = revTemp;
        }
    }
};
