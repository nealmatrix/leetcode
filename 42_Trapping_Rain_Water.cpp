//42. Trapping Rain Water

/* Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.*/

/* Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6*/

/* Solution:
- 计算after rain的面积(包括柱子的面积，但是不包括最后高于水面的面积)
- 然后计算before rain的面积(即柱子面积)，如果最后的柱子高于水面，要减掉
1. 从最左边i和最右边j向中间靠拢，height[i]和height[j]较小的向中间移动，因为大的移动不会增加面积
2. 如果较小的高于之前的水面pre_height,那么就计算多出的面积累积到after_rain_area
3. 最后会结束在i == j，这时候height[i]的高度可能会高于水面，且从来没计算过，需要最后减掉
*/
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0 || len == 1)
            return 0;
        int i = 0, j = len - 1;
        //记录上一次计算面积时的高度
        int pre_height = 0;
        //记录下雨后的面积(包括柱子的面积，但是不包括最后高于水面的面积)
        int after_rain_area = 0;
        while (i < j){
            if (height[i] <= height[j]){
                //如果较小的高于之前的高度，表示可以围更多的水
                if (height[i] > pre_height){
                    after_rain_area += (j - i + 1) * (height[i] - pre_height);
                    pre_height = height[i];
                }
                //较小的移动
                ++i;
            }else{
                if (height[j] > pre_height){
                    after_rain_area += (j - i + 1) * (height[j] - pre_height);
                    pre_height = height[j]; ;
                }
                --j;
            }
        }
        int before_rain_area = accumulate(height.begin(), height.end(), 0);
        //如果最后高于水面，需要减掉，这部分从未参与计算
        //如果是最后两个都高于水面，会触发计算，只是计算的面积中间没有水
        if (height[i] > pre_height)
            before_rain_area -= (height[i] - pre_height);

        return after_rain_area - before_rain_area;
    }
};

int main(){
    vector<int> height;
    Solution sol;

    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << endl;

    system("pause");
    return 0;
}