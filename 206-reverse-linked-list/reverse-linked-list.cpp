class Solution {
public:
    //ListNode* head;

    void reverse(ListNode* node) {
        

        reverse(node->next);

        node->next->next = node;
        node->next = NULL;
    }

    ListNode* reverseList(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return node;
        }
        //reverse(node);
        ListNode* st = node;
        ListNode* head = node -> next;
        ListNode* tail = node;
        while(head != nullptr){
            ListNode* temp = head -> next;
            head -> next = tail;
            tail = head;
            head = temp;
        }
        node -> next = nullptr;
        //head -> next = tail;
        return tail;
    }
};