//2 Add Two Numbers
/* Description:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

/*Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.*/

#include <iostream>
#include <fstream>
using namespace std;

class Data {
public:
	int a[50][100]; //每行记录在一个数组里面
	int b[50];
	int lineNum;
	void readData();
	void readDataLine(int line);
};
void Data::readData() {
	for (int i = 0; i < lineNum; i++) {
		for (int j = 0; j < b[i]; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << lineNum << "; ";
	for (int i = 0; i < lineNum; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}
void Data::readDataLine(int line) {
	for (int j = 0; j < b[line]; j++) {
		cout << a[line][j] << " ";
	}
	cout << endl;
}

int inputData(char* filename, Data& data) {
	ifstream inFile(filename, ios::in);
	if (!inFile) {
		cout << "error opening" << endl;
		return 0;
	}
	char buf[200];
	int bufSize = 200;
	int lineNum = 0; //一共多少行
	int num; //每行有多少data
	char*p;
	while (inFile.getline(buf, bufSize)) {
		p = strtok(buf, ", ");
		num = 0;
		while (p != NULL) {
			data.a[lineNum][num++] = atoi(p);
			p = strtok(NULL, ", ");
		}
		data.b[lineNum] = num;
		lineNum++;
	}
	data.lineNum = lineNum;
	inFile.close();
	return 1;
}
//definition for singly-linked list
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
//make list
ListNode* makeList(int* a, int num) {
	ListNode* first= new ListNode(a[0]);
	ListNode* p1, * p2;
	p1 = first;
	for (int i = 1; i < num; i++) {
		p2 = new ListNode(a[i]);
		p1->next = p2;
		p1 = p2;
	}
	return first;
}
//print linked list
void outputList(ListNode* p) {
	if (p != NULL) {
		cout << p->val;
		p = p->next;
		while (p != NULL) {
			cout <<" -> "<< p->val;
			p = p->next;
		}
		cout << endl;
	}
}

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//代码写法改进：
		//1.第一个点可以直接是虚构的，而实际第一个点为第二个点，避免代码的重复
		//2.第二个循环和第一个循环可以合并，只要设置到NULL后，加的数值为0即可，避免代码重复
		//
		/*int tmp,i=0; //tmp是每位想加的结果，i判断是否需要进位
		tmp = l1->val + l2->val + i;
		i = tmp / 10;
		tmp %= 10;
		l1 = l1->next;
		l2 = l2->next;
		ListNode* first = new ListNode(tmp);
		ListNode* p1, *p2;
		p1 = first;
		while (l1 != NULL &&l2 != NULL) {
			tmp = l1->val + l2->val + i;
			i = tmp / 10;
			tmp %= 10;
			p2 = new ListNode(tmp);
			p1->next = p2;
			p1 = p2;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l2 == NULL) {
			l2 = l1;
			l1 = NULL;
		}
		while (l1 == NULL &&l2 != NULL) {
			tmp = l2->val + i;
			i = tmp / 10;
			tmp %= 10;
			p2 = new ListNode(tmp);
			p1->next = p2;
			p1 = p2;
			l2 = l2->next;
		}
		if (i != 0) {
			p2 = new ListNode(i);
			p1->next = p2;
			return first;
		}
		return first;
		*/
		ListNode* prefirst = new ListNode(0); //第一个点为虚构的。
		ListNode* p = prefirst;
		ListNode* p1 = l1, *p2 = l2; //不要直接修改进来的参数变量
		int i=0, tmp; //i记录进位，tmp记录想加结果
		while (p1 != NULL || p2 != NULL) {
			int n1 = (p1 != NULL) ? p1->val : 0;
			int n2 = (p2 != NULL) ? p2->val : 0;
			tmp = n1 + n2 + i;
			i = tmp / 10;
			tmp %= 10;
			p->next = new ListNode(tmp);
			p = p->next;
			if (p1 != NULL) p1 = p1->next;
			if (p2 != NULL) p2 = p2->next;
		}
		if (i != 0) {
			p->next = new ListNode(i);
		}
		return prefirst->next;
	}
};

int main()
{
	Data data;
	char filename[] = "2_test.txt";
	inputData(filename, data);
	data.readData();
	Solution solution;
	cout << endl << "result: " << endl;
	for (int i = 0; i < data.lineNum / 2; i++) {
		ListNode* p1 = makeList(data.a[2 * i], data.b[2 * i]);
		ListNode* p2 = makeList(data.a[2 * i + 1], data.b[2 * i + 1]);
		outputList(p1);
		outputList(p2);
		ListNode* result = solution.addTwoNumbers(p1, p2);
		outputList(result);
	}
    return 0;
}

