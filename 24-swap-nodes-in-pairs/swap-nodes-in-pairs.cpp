class Solution {
public:
    ListNode* swapPairs(ListNode* curr) {
        if (curr == NULL || curr->next == NULL) {
            return curr;
        }

        ListNode* head = curr->next;
        ListNode* tail = curr;
        ListNode* prev = NULL;

        while (tail != NULL && tail->next != NULL) {
            ListNode* first = tail;
            ListNode* second = tail->next;
            ListNode* temp = second->next;

            // Swap
            second->next = first;
            first->next = temp;

            // Connect previous pair
            if (prev != NULL) {
                prev->next = second;
            }

            prev = first;
            tail = temp;
        }

        return head;
    }
};