class Solution {
public:
    ListNode* head;

    void reverse(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            head = node;
            return;
        }

        reverse(node->next);

        node->next->next = node;
        node->next = NULL;
    }

    ListNode* reverseList(ListNode* node) {
        head = NULL;
        reverse(node);
        return head;
    }
};