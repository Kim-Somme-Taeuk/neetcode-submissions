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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevSlow = nullptr;
        while (fast != nullptr && fast -> next != nullptr) {
            prevSlow = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prevSlow -> next = nullptr;
        ListNode* prev = nullptr;
        while(slow) {
            ListNode* next = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = next;
        }
        ListNode* second = prev;
        while(second) {
            if (head -> next != nullptr) {
                ListNode* head_next = head -> next;
                ListNode* second_next = second -> next;
                head -> next = second;
                second -> next = head_next;
                head = head_next;
                second = second_next;
            }
            else {
                head -> next = second;
                second = nullptr;
            }
        }
    }
};
