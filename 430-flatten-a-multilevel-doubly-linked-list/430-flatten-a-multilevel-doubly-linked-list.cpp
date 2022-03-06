/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head==NULL)return NULL;
        if (head->child!=NULL){
            Node* temp=head->next;
            head->child->prev=head;
            head->next=flatten(head->child);
            head->child=NULL;
            Node* A=head;
            while (A->next!=NULL)A=A->next;
            if (temp!=NULL)temp->prev=A;
            A->next=flatten(temp);
        }
        else head->next=flatten(head->next);
        return head;
    }
};