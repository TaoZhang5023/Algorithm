#include <map>
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *head;
    ListNode *list;
    if(l1 == NULL){
        return l2;
    }else if(l2 == NULL){
        return l1;
    }
    do{
        int val1 = l1? l1->val : 0;
        int val2 = l2? l2->val : 0;

        int val = (val1 + val2 + carry);
        carry = val/10;
        val = val%10;
        cout << val1 << " " << val2 << endl; 
        ListNode* tempNode = new ListNode(val);
        if(head == NULL){
            list = tempNode;
            head = list;
        }else{
            list->next = tempNode;
            list = list->next;
        }
        l1 = l1? l1->next : NULL;
        l2 = l2? l2->next : NULL;
    }while(l1 != NULL || l2 !=NULL || carry != 0);
    cout << endl;
    return head;
}

int main(){
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(5);
    int list1[] = {4,6};
    int list2[] = {6,4};
    ListNode* temp1 = new ListNode(list1[0]);
    l1->next = temp1;
    ListNode* temp2 = new ListNode(list2[0]);
    l2->next = temp2;
    ListNode* temp3 = new ListNode(list1[1]);
    l1->next->next = temp3;
    ListNode* temp4 = new ListNode(list2[1]);
    l2->next->next = temp4;
    ListNode * ans = addTwoNumbers(l1,l2);
    while(ans != NULL){
        cout << ans -> val;
        ans = ans->next;
    }
    return 0;
}