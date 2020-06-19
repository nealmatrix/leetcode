//21 Merge Two Sorted Lists

/* Description:
Merge two sorted linked lists and return it as a new sorted list. 
The new list should be made by splicing together the nodes of the first two lists.*/

/* Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*/

/* Solution：
和merge sort最后merge步骤是一样的，但是这个算法会改变input l1和l2*/

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

//Generate linked list
ListNode* generate_linked_list(vector<int> & array){
    ListNode* last = nullptr;
    int length = array.size();
    for(int i = length - 1; i >= 0; --i){
        last = new ListNode(array[i], last);
    }
    return last;
}

//Print linked list
void print_linked_list(ListNode* head){
    ListNode* p = head;
    while (p -> next != nullptr){
        cout << p -> val << "->";
        p = p -> next;
    }
    cout << p -> val << endl;
}

class Solution {
public:
    //会改变input l1和l2这两个linked list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1_pointer = l1, * l2_pointer = l2;
        //定义一个虚拟的head_pre
        ListNode* head_pre = new ListNode(0);
        ListNode* head_pointer = head_pre;
        while (l1_pointer && l2_pointer){
            if (l1_pointer -> val <= l2_pointer -> val){
                head_pointer -> next = l1_pointer;
                l1_pointer = l1_pointer -> next;
            }
            else{
                head_pointer -> next = l2_pointer;
                l2_pointer = l2_pointer -> next;  
            }
            head_pointer = head_pointer -> next;
        }
        if (!l1_pointer){
            head_pointer -> next = l2_pointer; 
        }else{
            head_pointer -> next = l1_pointer; 
        }
        return head_pre -> next;
    }
};

int main(){
    vector<int> array;
    ListNode* l1, * l2, * result;
    Solution sol;

    cout << "Expect: 1->1->2->3->4->4" << endl;
    array = {1,2,4};
    l1 = generate_linked_list(array);
    cout << "l1: ";
    print_linked_list(l1);
    array = {1,3,4};
    l2 = generate_linked_list(array);
    result = sol.mergeTwoLists(l1, l2);
    cout << "Output: ";
    print_linked_list(result);
    cout << "l1: ";
    print_linked_list(l1);
}