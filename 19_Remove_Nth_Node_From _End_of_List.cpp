//19 Remove Nth Node From End of List

/* Description:
Given a linked list, remove the n-th node from the end of list and return its head.*/

/* Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.*/

/* Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?*/

/* Solution:
1. 确定nth node from the end of the list的前一个node，因为需要：
nth_pre -> next = nth_pre -> next -> next;
2. 需要有一个head_pre，为head前面的一个虚假的node，next指向head，因为如果head为nth node，
为了1需要有一个head前面的node
3. 记得delete nth node, 需要在1之前记录nth node的pointer，否则1之后找不到nth node了,会造成
内存泄漏*/

#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//construct a signly-linked list by array
ListNode* generateLinkedList(vector<int> & array){
    int length = array.size();
    ListNode* last = nullptr;
    for (int i = length - 1; i >= 0; --i){
        last = new ListNode(array[i], last);
    }
    return last;
}

//print a linked list
void printLinkedList(ListNode* head){
    ListNode* p = head;
    while (p -> next != nullptr){
        cout << p -> val << "->";
        p = p -> next;
    }
    cout << p -> val << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //为方便后面的逻辑，在linked list最前面加入一个虚拟的node, val = 0, next = pointer to first
        ListNode* head_pre = new ListNode(0, head);
        
        //the predecessor of the nth node from the end of list 
        ListNode* nth_pre = head_pre;
        ListNode* p = head_pre;

        for (int i = 0; i < n; ++i){ //等价于 while (n--)
            p = p -> next;
        }
        while (p -> next != nullptr){ //等价于while (p -> next)
            p = p -> next;
            nth_pre = nth_pre -> next;
        }
        ListNode* nth = nth_pre -> next;
        nth_pre -> next = nth_pre -> next -> next;
        delete nth;

        return head_pre -> next;
    }
};

int main(){
    Solution s;
    //case 1
    {vector<int> array({1,2,3,4,5});
    int n = 2;
    cout << "case 1: output 1->2->3->5" << endl;
    ListNode * head = generateLinkedList(array);
    head = s.removeNthFromEnd(head, n);
    printLinkedList(head);}

    //case 2
    {vector<int> array({1,2,3,4,5});
    int n = 5;
    cout << "case 2: output 2->3->4->5" << endl;
    ListNode * head = generateLinkedList(array);
    head = s.removeNthFromEnd(head, n);
    printLinkedList(head);}

    system("pause");
    return 0;
}