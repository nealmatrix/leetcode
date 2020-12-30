/*
56. Merge Intervals
Medium

5994

344

Add to List

Share
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
/*Solution
1. 将intervals中的interval按照start从小到大排列
2. 将intervals[0]插入result中
3. 如果result[0][1] >= intervals[1][1]，说明result[0]和intervals[1]有overlap，这样更改result[0]的end值
4. 如果result[0][1] < intervals[1][1]，说明result[0]和intervals[1]没有overlap，这样将intervals[1]加入到result
5. 以此类推
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), Solution::lessVector );
        result.push_back(intervals[0]);
        int lastResultIndex;

        for (int i = 1; i < intervals.size(); ++i){
            lastResultIndex = result.size() - 1;
            if (result[lastResultIndex][1] >= intervals[i][0]){
                result[lastResultIndex][1] = max(intervals[i][1], result[lastResultIndex][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    static bool lessVector(vector<int>& v1, vector<int>& v2){
        //查看CPP compare的requirement需要compare(a,a)为False，所以这里不能是<=
        return v1[0] < v2[0];
    }

};
void printVector2D(vector<vector<int>> result){
    for (int i = 0; i < result.size(); ++i){
        for (int j = 0; j < result[i].size(); ++j){
            cout << result[i][j] << ' ';
        }
        cout << "|";
    }
    cout << endl;
}
int main(){
    Solution sol;
    vector<vector<int>> intervals;

    intervals = {{1,3},{8,10},{2,6},{15,18}};
    printVector2D(sol.merge(intervals));

    intervals = {{1,4},{4,5}};
    printVector2D(sol.merge(intervals));

    intervals = {{1,4},{1,5}};
    printVector2D(sol.merge(intervals));

    intervals = {{74,78},{61,63},{46,50},{51,54}};
    printVector2D(sol.merge(intervals));

    return 0;


}