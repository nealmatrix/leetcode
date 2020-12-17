//4 Median of Two Sorted Arrays

/* Description:
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays A, B.
The overall run time complexity should be O(log(m + n)).
You may assume nums1 and nums2 cannot be both empty.*/

/*Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is(2 + 3) / 2 = 2.5
*/

/* Solution:
将A, B各分成两部分
A left: A[0]...A[i-1] 和 A right: A[i]...A[m-1]
B left: B[0]...B[j-1] 和 B right: B[j]...A[n-1]
如果左边部分和右边部分满足如下条件，即可知道中位数就在分界线
1. 左边数量等于右边
   len(A left + B left) = len(A right + B right)
   i + j = m - i + n - j
2. 左边都小于右边
   A[i-1] <= B[j] && B[j-1] <= A[i]
i如果确定， 根据1，j就是确定的
那么根据2，可以对i进行二分法找到i来保证2成立，即m + n 进行二分法，复杂度为 O(log(m + n)
*/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> *num1, *num2;
		if (nums1.size() > nums2.size()){
			num1 = &nums2;
			num2 = &nums1;
		}
		else {
			num1 = &nums1;
			num2 = &nums2;
		}
		vector<int>& numA = *num1;
		vector<int>& numB = *num2;
		int m = numA.size();
		int n = numB.size();

		int i, j;
		//case 0: m = 0,
		if (m == 0) {
			if (n % 2 == 0)
				return (numB[n / 2 - 1] + numB[n / 2]) / 2.0;
			else
				return numB[n / 2];
		}
			

		//case 1: i = 0, j = (m+n)/2 , B[j-1]<=A[0]
		i = 0;
		j = (m + n) / 2;
		if (numB[j - 1] <= numA[0]) {
			if (n == m)
				// n == m, j = n, special case
				return (numB[j - 1] + numA[i]) / 2.0;
			else {
				if ((m + n) % 2 == 0)
					return (numB[j - 1] + min(numA[i], numB[j])) / 2.0;
				else
					return min(numA[i], numB[j]);
			}
		}
		//case 2: i = m, j= (n - m)/2
		i = m;
		j = (n - m) / 2;
		if (numA[i - 1] <= numB[j]) {
			if (m == n)
				// n ==m, j =0, special case
				return (numA[i - 1] + numB[j]) / 2.0;
			else {
				if ((m + n) % 2 == 0)
					return (max(numA[i - 1], numB[j - 1]) + numB[j]) / 2.0;
				else
					return numB[j];
			}
		}
		//case 3: i = 1...m-1, j = 1...n-1
		int minI = 1;
		int maxI = m - 1;
		i = (minI + maxI) / 2;
		j = (m + n) / 2 - i;
		while (numA[i - 1] > numB[j] || numB[j - 1] > numA[i]) {
			if (numA[i - 1] > numB[j]) {
				maxI = i;
			}
			else if (numB[j - 1] > numA[i]) {
				minI = i;
				if (maxI - minI == 1)
					minI = i + 1;
			}
			i = (minI + maxI) / 2;
			j = (m + n) / 2 - i;
		}
		if ((m + n) % 2 == 0) {
			return (max(numA[i - 1], numB[j - 1]) + min(numA[i], numB[j])) / 2.0;
		}
		else
			return min(numA[i], numB[j]);
	}
};

int main()
{
	//test 1 return 2.5
	/*int a[2] = { 1, 2 };
	int b[2] = { 3, 4 };
	vector<int> nums1(a, a + 2);
	vector<int> nums2(b, b + 2);
	*/

	//test 2 return 2
	/*int a[2] = { 1, 3 };
	int b[1] = { 2 };
	vector<int> nums1(a, a + 2);
	vector<int> nums2(b, b + 1);*/

	//test 3 return 2.5
	/*int b[2] = { 2,3 };
	vector<int> nums1;
	vector<int> nums2(b, b + 2);*/

	//test 4 return 1
	/*int a[1] = { 1 };
	int b[1] = { 1 };
	vector<int> nums1(a, a + 1);
	vector<int> nums2(b, b + 1);*/

	//test 5 return 4
	/*int a[3] = { 1, 3, 7 };
	int b[4] = { 2, 4, 6, 8 };
	vector<int> nums1(a, a + 3);
	vector<int> nums2(b, b + 4);*/

	//test 6 return 9
	int a[6] = { 1, 3, 7, 10, 20, 21 };
	int b[8] = { 2, 4, 6, 8, 11, 13, 19, 100 };
	vector<int> nums1(a, a + 6);
	vector<int> nums2(b, b + 8);

	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2)<<endl; 
	
	/*int c = 7;
	cout << c / 2 << endl;
	cout << double(c) / 2 << endl;
	cout << c / 2.0 << endl;
	int d = 10;
	cout << min(c, d) << endl;*/
	system("pause");
    return 0;
}

