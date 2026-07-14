/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        while(temp != nullptr){
            Node* copy = new Node(temp->val);
            copy -> next = temp -> next;
            temp -> next = copy;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=nullptr){
            Node* copy = temp -> next;
            copy->random = (temp->random != nullptr) ? temp->random->next : nullptr;
            temp = temp->next->next;
        }

        Node* dNode = new Node(-1);
Node* res = dNode;

temp = head;

while(temp != nullptr){
    Node* copy = temp->next;

    res->next = copy;
    res = copy;

    temp->next = copy->next;
    temp = temp->next;
}
        return dNode->next;
    }
};