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

    ListNode* findKth(ListNode* temp, int k){
        k = k - 1;

        while(temp != NULL && k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* front = temp -> next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while(temp!=nullptr){
            ListNode* KthNode = findKth(temp, k);
            if(KthNode == nullptr){
                if(prevNode) prevNode -> next = temp;
                break;
            }

            ListNode* nextNode = KthNode -> next;
            KthNode -> next = nullptr;
            reverseLL(temp);
            if(temp == head){
                head = KthNode;
            }
            else{
                prevNode -> next = KthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};