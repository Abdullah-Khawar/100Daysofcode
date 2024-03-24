class Solution {
public:
    ListNode* curr; // Pointer to track current node during recursion

    // Recursive function to check if a linked list is a palindrome
    bool solve(ListNode* head) {
        // Base case: if head is nullptr, the list is empty and is considered a palindrome
        if (!head) 
            return true;

        // Recursively traverse the list
        bool ans = solve(head->next);

        // Check if the value of the current node matches the value of the corresponding node from the end
        if (curr->val != head->val) 
            return false; // If values don't match, the list is not a palindrome
        curr = curr->next; // Move curr pointer to the next node

        return ans; // Return result obtained from previous recursive call
    }

    bool isPalindrome(ListNode* head) {
        curr = head; // Initialize curr pointer with the head of the list
        return solve(head); // Call recursive function to determine if list is a palindrome
    }
};
