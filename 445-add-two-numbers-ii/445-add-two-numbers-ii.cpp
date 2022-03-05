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
    void addNums(ListNode* l1, ListNode* l2, int &carry){
        if (l1==NULL)return;
        addNums(l1->next,l2->next,carry);
        // cout<<l1->val<<" "<<l2->val<<" "<<carry<<endl;
        int temp=(l1->val+l2->val+carry)%10;
        carry=(l1->val+l2->val+carry)/10;
        l1->val=temp;
        return;
    }
    
    void addCarry(ListNode* l1, ListNode* temp, int &carry){
        if (l1==temp)return;
        addCarry(l1->next,temp,carry);
        int temp2=(l1->val+carry)%10;
        carry=(l1->val+carry)/10;
        l1->val=temp2;
    }
    
    int getSize(ListNode* l){
        ListNode* temp=l;int ans=0;
        while (temp!=NULL){
            ans++;temp=temp->next;
        }
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=getSize(l1);
        int len2=getSize(l2);
        if (len2>len1)return addTwoNumbers(l2,l1);
        int diff=len1-len2;
        ListNode* temp=l1;
        while (diff--)temp=temp->next;
        ListNode* ans = new ListNode();
        int carry=0;
        addNums(temp,l2,carry);
        // return l1;
        addCarry(l1,temp,carry);
        if (carry!=0){
            ListNode* ans=new ListNode(carry);ans->next=l1;
            return ans;
        }
        return l1;
    }
};