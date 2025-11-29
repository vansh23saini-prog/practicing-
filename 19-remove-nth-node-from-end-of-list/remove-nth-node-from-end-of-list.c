struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // move fast n steps
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // move both until fast is at last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // delete target node
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    // ALWAYS return something of type struct ListNode*
    return dummy.next;
}
