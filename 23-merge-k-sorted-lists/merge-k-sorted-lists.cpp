class Solution {
public:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(a != NULL && b != NULL) {
            
            if(a->val < b->val) {
                temp->next = a;
                a = a->next;
            }
            else {
                temp->next = b;
                b = b->next;
            }

            temp = temp->next;
        }

        if(a != NULL) {
            temp->next = a;
        }
        else {
            temp->next = b;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) {
            return NULL;
        }

        ListNode* ans = lists[0];

        for(int i = 1; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }
};