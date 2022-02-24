//34. Find First and Last Position of Element in Sorted Array

/* Description:
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].*/

/* Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/

/* Solution:
参考Q33的二分法技巧2*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0 || (len == 1 && target != nums[0]))
            return {-1, -1};
        if (len == 1 && target == nums[0])
            return {0, 0};
        vector<int> result;
        int min_i = 0, max_i = len -1;
        int mid;
        //target的下限一定在min_i和max_i中
        while (min_i < max_i){
            if (max_i - min_i == 1)
                break;
            mid = (min_i + max_i) / 2;
            if (target <= nums[mid])
                max_i = mid;
            else
                min_i = mid;
        }
        if (target == nums[min_i])
            result.push_back(min_i);
        else if (target == nums[max_i])
            result.push_back(max_i);
        else
            return {-1, -1};
        
        min_i = 0, max_i = len -1;
        while (min_i < max_i){
            if (max_i - min_i == 1)
                break;
            mid = (min_i + max_i) / 2;
            if (target >= nums[mid])
                min_i = mid;
            else
                max_i = mid;
        }
        if (target == nums[max_i])
            result.push_back(max_i);
        else if (target == nums[min_i])
            result.push_back(min_i);
        return result;
    }
};

int main(){
    vector<int> nums;
    Solution sol;
    int target;
    vector<int> result;

    cout << "Expect: 3,4" << endl;
    nums = {5,7,7,8,8,10};
    target = 8;
    result = sol.searchRange(nums, target);
    cout << "Output: " << result[0] << "," << result[1]<< endl;

    cout << "Expect: -1,-1" << endl;
    nums = {5,7,7,8,8,10};
    target = 6;
    result = sol.searchRange(nums, target);
    cout << "Output: " << result[0] << "," << result[1]<< endl;

    system("pause");
    return 0;
}