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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        
        ListNode* first = head;
        ListNode* second = head;
        
        //if k > length of LL then reduce it by taking mod
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        k = k%len;
        
        for(int i=0; i<k; i++){
            if(second->next == NULL){
                second = head;
            } else {
                second = second->next;
            }
        }
        
        while(second->next != NULL){
            first = first->next;
            second = second->next;
        }
        
        second->next = head;
        head = first->next;
        first->next = NULL;
        return head;
    }
};