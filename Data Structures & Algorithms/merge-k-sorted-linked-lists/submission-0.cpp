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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (list1 && list2) {
            while (list1 && list1->val <= list2->val) {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
            while (list1 && list2 && list1->val > list2->val) {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }

        if (list1) cur->next = list1;
        else if (list2) cur->next = list2;

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (ListNode* head : lists) {
            res = mergeTwoLists(res, head);
        }

        return res;
    }
};
