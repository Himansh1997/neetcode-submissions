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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head == NULL || head->next == NULL)
        // return NULL;

        ListNode* dummy= new ListNode(-1);
        dummy->next= head;

        ListNode* firstNode= dummy;
        ListNode* secondNode= dummy;

        while(n > 0){
            secondNode= secondNode->next;
            n--;
        }

        while(secondNode->next != NULL)
        {
            firstNode= firstNode->next;
            secondNode= secondNode->next;
        }

        firstNode->next= firstNode->next->next;
        return dummy->next;
    }
};