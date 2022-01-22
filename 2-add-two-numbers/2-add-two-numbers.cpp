/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==NULL)return l2;
        else if (l2==NULL)return l1;
        ListNode* ans=new ListNode(0);
        ListNode* ret=ans;
        int carry=0;
        ans->val=l1->val+l2->val+carry;
        carry=ans->val/10;
        ans->val=ans->val%10;
        l1=l1->next;l2=l2->next;
        while (l1!=NULL && l2!=NULL){
            ans->next=new ListNode(0);ans=ans->next;
            ans->val=l1->val+l2->val+carry;
            carry=ans->val/10;
            ans->val=ans->val%10;
            cout<<ans->val<<endl;
            l1=l1->next;
            l2=l2->next;
        }
        while (l1!=NULL){
            ans->next=new ListNode(0);ans=ans->next;
            ans->val=l1->val+carry;
            carry=ans->val/10;
            ans->val=ans->val%10;
            cout<<ans->val<<endl;
            l1=l1->next;
        }
        while (l2!=NULL){
            ans->next=new ListNode(0);ans=ans->next;
            ans->val=l2->val+carry;
            carry=ans->val/10;
            ans->val=ans->val%10;
            cout<<ans->val<<endl;l2=l2->next;
        }
        if (carry!=0){
            ans->next=new ListNode(0);ans=ans->next;
            ans->val=carry;
        }
        return ret;
    }
};