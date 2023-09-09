//23 Merge k Sorted Lists
/* Description:
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.*/

/* Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6*/

/* Solution: priority_queue
思路和mergesort类似
1. 每次比较k个list中最小的数，将其定义给新的sorted linked lists
2. 因为是重复取最小的数，所以用heap data structure，每次取最小或者最大的元素，复杂度为O(logk)而不是O(k)*/

/* 复杂度：
1. 最开始插入k个，因为要检测是否为nullptr，所以要一个一个插入，复杂度为klogk
(其实时log1 + log2 + log3 + ... + logk)
2. 每次取最小，复杂度为O(logk)，取了N个，N为所有元素总数，复杂度为O(Nlogk)
总复杂度为O(Nlogk)*/

#include <queue>
#include <map>
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Generate linked list based on array
ListNode* generateLinkedList(vector<int> && array){
    ListNode* last = nullptr;
    int length = array.size();
    for (int i = length - 1; i >= 0; --i)
        last = new ListNode(array[i], last);
    return last;
}

//Print linked list
int printLinkedList(ListNode* head){
    if (head == nullptr){
        cout << endl;
        return 0;
    }
        
    ListNode* p = head;
    while (p -> next != nullptr){
        cout << p -> val << "->";
        p = p -> next;
    }
    cout << p -> val << endl;
    return 0;
}
//write my own compare
struct MyCompare{
    bool operator()(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head_pre = new ListNode();
        ListNode* ptr = head_pre;
        
        ListNode * min_ptr;
        
        int num_lists = 0;
        //每次取最小都从priority_queue中取，需要每个元素检测，不能有nullptr插入，不然MyCompare都无法比较
        priority_queue<ListNode*, vector<ListNode*>, MyCompare> pq;
        for (unsigned int i = 0; i < lists.size(); ++i){
            if (lists[i] != nullptr){
                pq.push(lists[i]);
                ++num_lists;
            }       
        }
        
        // while(!pq.empty()){
        //     min_ptr = pq.top();
        //     ptr->next = min_ptr;
        //     pq.pop();
        //     if (min_ptr->next != nullptr)
        //         pq.push(min_ptr->next);
        //     ptr = ptr->next;
        // }
        while(!pq.empty()){
            min_ptr = pq.top();
            ptr->next = min_ptr;
            pq.pop();
            if (num_lists > 1){
                if (min_ptr->next != nullptr)
                    pq.push(min_ptr->next);
                else{
                    
                    --num_lists;
                }
                ptr = ptr->next;
            }
            //当pq中只剩下一个list时，就可以break，直接将后面的list接到result后面
            //但这样写在leetcode上run速度还不如上面注释的，并没有管一个list的情况
            else
                break;
        }
        return head_pre->next;
    }
};

int main(){
    ListNode* l1, * l2, * l3;
    vector<ListNode*> lists;
    Solution sol;

    cout << "Expect: 1->1->2->3->4->4->5->6" << endl;
    l1 = generateLinkedList({1,4,5});
    l2 = generateLinkedList({1,3,4});
    l3 = generateLinkedList({2,6});
    lists = {l1, l2, l3};
    cout << "Output: ";
    printLinkedList(sol.mergeKLists(lists));

    cout << "Expect: \"\"" << endl;
    l1 = generateLinkedList({});
    lists = {l1};
    cout << "Output: ";
    printLinkedList(sol.mergeKLists(lists));
    system("pause");
    return 0;
}