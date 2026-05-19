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
        if(lists.empty()) return nullptr;

        while(lists.size() > 1) {
            vector<ListNode*> merged;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;

                merged.push_back(mergeTwoLists(l1, l2));
            }

            lists = merged;
        }

        return lists[0];
    }
};
