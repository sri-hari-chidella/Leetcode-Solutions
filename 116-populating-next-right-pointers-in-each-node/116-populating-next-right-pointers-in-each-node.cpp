/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==NULL)return NULL;
        if (root->left!=NULL && root->right!=NULL){
            root->left->next=root->right;
            root->right->next=root->next!=NULL?(root->next->left!=NULL?root->next->left:root->next->right):NULL;
        }
        else if (root->left!=NULL && root->right==NULL){
            root->left->next=root->next!=NULL?(root->next->left!=NULL?root->next->left:root->next->right):NULL;
        }
        else if (root->left==NULL && root->right!=NULL){
            root->right->next=root->next!=NULL?(root->next->left!=NULL?root->next->left:root->next->right):NULL;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};