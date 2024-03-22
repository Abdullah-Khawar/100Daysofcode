class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Initialize pointers to traverse the list
        ListNode* left = nullptr;
        ListNode* right = list1;

        // Traverse to find the node before 'a'
        for (int i = 0; i <= b; i++) {
            if (i == a - 1) {
                left = right;
            }
            right = right->next;
        }

        // Connect the node before 'a' to the head of list2
        left->next = list2;

        // Traverse to the end of list2
        while (list2->next != nullptr) {
            list2 = list2->next;
        }

        // Connect the end of list2 to the node after 'b'
        list2->next = right;

        // Return the modified list1
        return list1;
    }
};
