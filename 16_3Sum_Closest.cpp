//16. 3Sum Closest
/* Description:
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.*/

/* Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

/* Constraints:
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4*/

/* Solution: 和15_3Sum的Solution 2思路一样, 如下：
还是先sort nums，从左向右，为a，确定a后，即确定target，这时候，b和c从右侧的数组两侧向
中间靠拢
case 1： b + c < target， 那么b向右移动
case 2： b + c > target， 那么c向左移动
case 3： b + c = target， 那么b和c一起向中间移动
此时也要注意a，b，c重复的问题，类似于solution中的bigIter函数的功能
复杂度仍为O(n^2)*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int temp_result;
        int i = 0, j = i + 1, k = len - 1;
        //定义一个初始的result和diff，这里用int的最大值也可以，或者参考题目中的constraints
        int result = nums[i] + nums[j] + nums[k];
        int diff = abs(result - target);

        while (i < len -2){  
            //i不同，j和k的初始值也不同
            j = i + 1, k =len -1;
            while (j < k){
                temp_result = nums[i] + nums[j] + nums[k];
                if (temp_result == target)
                    return temp_result;
                //如果temp_result > target,说明k太大了，移动k即可，同理应用于<情况
                if (temp_result > target){
                    if (temp_result - target < diff){
                        //update result and diff simutaneously
                        result = temp_result;
                        diff = temp_result - target;
                    }
                    //update k时，要跳过重复的，同理应用于j和i
                    while ((k - 1) > j && nums[k - 1] == nums[k])
                        --k;
                    --k;
                }else{
                    if (target - temp_result < diff){
                        result = temp_result;
                        diff = target - temp_result;
                    }
                    while ((j + 1) < k && nums[j + 1] == nums[j])
                        ++j;
                    ++j;
                }
            }
            while ((i + 1) < len && nums[i + 1] == nums[i])
                ++i;
            ++i;
        }
        return result;
    }
};
int main(){
    Solution s;
    int result;
    //case 1:
    cout << "case 1: output 2" << endl;
    {vector<int> nums({-1, 2, 1, -4});
    result = s.threeSumClosest(nums, 1);
    cout << result << endl;}

    //case 2:
    cout << "case 2: output 6" << endl;
    {vector<int> nums({-4, 1, 2, 2, -3, 2, 1, -4});
    result = s.threeSumClosest(nums, 100);
    cout << result << endl;}

    //case 3: output -2
    cout << "case 3: output -2" << endl;
    {vector<int> nums({-4, 1, 2, 2, -3, 2, 1, -4});
    result = s.threeSumClosest(nums, -2);
    cout << result << endl;}

    //case 4: output 2
    cout << "case 4: output 2" << endl;
    {vector<int> nums({1, 1, 1, 0});
    result = s.threeSumClosest(nums, -100);
    cout << result << endl;}

    //case 5: output 16
    cout << "case 5: output 16" << endl;
    {vector<int> nums({-111,-111,3,6,7,16,17,18,19});
    result = s.threeSumClosest(nums, 13);
    cout << result << endl;}
    system("pause");
    return 0;
}