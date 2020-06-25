//41. First Missing Positive

/* Description:
Given an unsorted integer array, find the smallest missing positive integer.*/

/* Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1*/

/*Note:
Your algorithm should run in O(n) time and uses constant extra space.*/

/* Solution:
len = nums.size()
- 如果nums将1...len都占了，那么return len + 1
- 如果nums未占满1...len，那么return 1...len中的某个值
- 所以关键在于1...len中的值
- 为保证extra space为O(1)，只能对nums进行操作*/

#include <vector>
#include <iostream>
using namespace std;

class Solution_2 {
public:
    //extra space is not constant, is O(n)
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        vector<int> label(len, 0);
        for (int i = 0; i < len; ++i){
            if (nums[i] > 0 && nums[i] <= len)
                label[nums[i] - 1] = 1;
        }
        for (int i = 0; i < len; ++i){
            if (label[i] == 0)
                return i + 1;
        }
        return len + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int abs_num;
        for (int i = 0; i < len; ++i){
            //将不符合1...len的值都设置为len+1，方便后面做label
            if (nums[i] <= 0 || nums[i] > len)
                nums[i] = len + 1;
        }
        for (int i = 0; i < len; ++i){
            abs_num = abs(nums[i]);
            //1...len中被nums占了的设置为负数
            if (abs_num <= len)
                nums[abs_num - 1] = -abs(nums[abs_num - 1]);
        }
        //第一个不为负数的就是结果
        for (int i = 0; i < len; ++i){
            if (nums[i] > 0)
                return i + 1;
        }
        return len + 1;
    }
};

int main(){
    vector<int> nums;
    Solution sol;

    cout << "Expect: 3" << endl;
    nums = {1,2,0};
    cout << "Output: " << sol.firstMissingPositive(nums) << endl;

    cout << "Expect: 2" << endl;
    nums = {3,4,-1,1};
    cout << "Output: " << sol.firstMissingPositive(nums) << endl;;

    cout << "Expect: 1" << endl;
    nums = {7,8,9,11,12};
    cout << "Output: " << sol.firstMissingPositive(nums) << endl;;

    system("pause");
    return 0;
}