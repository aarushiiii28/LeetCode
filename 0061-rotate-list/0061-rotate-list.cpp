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

        if(head == nullptr || head -> next == nullptr) return head;

        int l;
        ListNode* temp = head;

        while(temp != nullptr){
            temp = temp->next;
            l++;
        }
        while(k%l > 0){
            ListNode* temp= head;
            while(temp->next->next!=nullptr){
                temp = temp -> next;
            }
            
            ListNode* newHead = temp -> next;
            temp -> next = nullptr;
            newHead -> next = head;
            head = newHead; 

            k--;
        }
        return head;
    }
};