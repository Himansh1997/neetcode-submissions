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
    ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* curr= &dummy;

    while(l1 && l2){
        if(l1->val < l2->val){
            curr->next= l1;
            l1= l1->next;
        }else{
            curr->next= l2;
            l2= l2->next;
        }
        curr= curr->next;
    }
    if(l1){
        curr->next= l1;
    }
    if(l2){
        curr->next= l2;
    }
    return dummy.next;
}
    ListNode* solve(vector<ListNode*>& lists, int start, int end){
        if(start > end){
            return NULL;
        }
        if( start == end){
            return lists[start];
        }
        int mid= start + (end-start)/2;
        ListNode* left= solve(lists, start, mid);
        ListNode* right= solve(lists, mid+1, end);

        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size() == NULL){
            return NULL;
        }
        return solve(lists, 0, lists.size()-1);
    }
};
