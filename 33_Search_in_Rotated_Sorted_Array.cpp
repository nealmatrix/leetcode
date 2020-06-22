//33. Search in Rotated Sorted Array

/* Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, 
otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).*/

/* Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1*/

/* Solution:
1. 二分法技巧：
while (min_i <= max_i)
    如果target > nums[j], 那么min_i = j + 1，而不是j
    如果target < nums[j], 那么max_i = j - 1，而不是j
这样会节省很多种选择*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        int min_i = 0, max_i = len - 1;
        int j = (min_i + max_i) / 2;
        int nums_begin = nums[min_i], nums_end = nums[max_i];
        //如果有rotate, 判断target是否是在左向上还是右向下
        bool is_left = (target >= nums_begin) ? true : false;
        //判断序列是否有rotate
        bool is_rotate = (nums_begin > nums_end) ? true : false;

        while (min_i <= max_i){
            j = (min_i + max_i) / 2;
            if (is_rotate){
                if (is_left){
                    //这样target一定在j的左边，所以max_i = j - 1 
                    if (nums[j] <= nums_end){
                        max_i = j - 1;
                        continue;
                    }
                }
                else{
                    //这样target一定在j的右边，所以min_i = j + 1
                    if (nums[j] >= nums_begin){
                        min_i = j + 1;
                        continue;
                    }
                }
            }  
            if (target == nums[j])
                return j;
            else if (target < nums[j])
                max_i = j - 1;
            else
                min_i = j + 1;
           
        }
        return -1; 
    }
};

int main(){
    vector<int> array;
    int target;
    Solution sol;

    cout << "Expect: 4" << endl;
    array = {4,5,6,7,0,1,2};
    target = 0;
    cout << "Output: " << sol.search(array, target) << endl;

    cout << "Expect: -1" << endl;
    array = {4,5,6,7,0,1,2};
    target = 3;
    cout << "Output: " << sol.search(array, target) << endl;

    cout << "Expect: 1" << endl;
    array = {1,3};
    target = 3;
    cout << "Output: " << sol.search(array, target) << endl;

    system("pause");
    return 0;
}