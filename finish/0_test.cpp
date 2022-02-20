// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;

/*
class Data {
public:
	int a[10][6];
	int b[10]; //记录每个数组有多少个数
	int lineNum = 0; //记录一共有几行
	void readData();
};
void Data::readData() {
	for (int line = 0; line < lineNum; line++) {
		cout << "line " << line << ": ";
		for (int num = 0; num < b[line]; num++) {
			cout << a[line][num] << " ";
		}
		cout << endl;
	}
	cout << "lineNum" << lineNum << "; ";
	for (int line = 0; line < lineNum; line++) {
		cout << b[line] << " ";
	}
	cout << endl;
}
*/

int main()
{
	//test 基本输入输出
    /*double n = 2;
	int m = sizeof(n);
	cout << n << endl;
	cout << "size n: " << m << endl;
	*/

	//字符数组的分割 相当于python的split功能
	/*char s[] = "1,2,3,4,5";
	char *p;
    p=strtok(s, ",");
	while (p != NULL) {
		cout << p << endl;
		p = strtok(NULL, ",");
	}
	*/

	//test 文件的输入和输出
	/*int a[10];
	int total = 0;
	ifstream inFile("test_input1.txt", ios::in);
	if (!inFile) {
		cout << "error opening" << endl;
		return 0;
	}
	int x;
	while (inFile >> x)
		a[total++] = x;
	for(int i=0; i<total; i++)
    	cout << a[i] << endl;
	inFile.close();
	*/

	//test 从文件中读取n行数，分别存入数组中
    /*Data data;
	ifstream inFile("test_input2.txt", ios::in);
	if (!inFile) {
		cout << "error opening" << endl;
		return 0;
	}
	int bufSize=20;
	char buf[20];
	int num;
	char *p;
	while (inFile.getline(buf, bufSize)) {
		p = strtok(buf, " ");
		num = 0;
		while (p != NULL) {
			data.a[data.lineNum][num++] = atoi(p);
			p = strtok(NULL, " ");
		}
		data.b[data.lineNum] = num;
		data.lineNum++;
	}
	inFile.close();
	data.readData();
	*/

	//test 地址赋值
	/*int m = 1, n = 2;
	int *a, *b;
	b = &m;
	a = b;
	cout << *a<<endl;
	b = &n;
	cout << *a << endl;
	*/

	//test 字符串数组的大小
	/*int a[] = { 1,2,3,4 };
	int *b;
	char c[] = "abcdefg";
	string d = "abcdefg";
	string e = "abc";
	cout << "a: " << sizeof(a)<<endl;
	cout << "*b:" << sizeof(b)<<endl;
	cout << "c: " << sizeof(c)<<endl;
	cout << "d size: " << d.size() << endl;
	cout << "d: " << sizeof(d) << endl;
	cout << "e: " << sizeof(e) << endl;
	cout << d.at(1) << endl;*/

	//unordered_map 插入的是对象本身还是指针？
	/*unordered_map<char, int> m;
	pair<char, int> p1 = make_pair('a', 2);
	m.insert(p1);
	m['a'] = 3;
	cout << m['a'] << endl << p1.second << endl;*/

	//test substr
	string s = "abcd";
	cout << s.substr(0, 2)<<endl;
	cout << s.substr(0, 0)<<endl;
	cout << s.substr(2)<<endl;
	cout << s.substr(4)<<endl;
    return 0;
}

