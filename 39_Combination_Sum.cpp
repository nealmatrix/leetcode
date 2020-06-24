//39. Combination Sum

/* Description:
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.*/

/* Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.*/

/* Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]*/

/* Solution:recursive
建立新函数，如下目的为只用到end_pos index的candidates进行组合，和为target，并且在下面递归中
end_pos必然用到一次，所以结果不会重复
vector<vector<int>> combinationSumPos(vector<int>& candidates, int target, int end_pos);
base case:
1. 如果target < 0, 返回空result
2. 如果candidates[0]-candidates[end_pos]有等于target，加入到result中
recursive：
1. 如果没有就进入recursive
i: 0...end_pos
combinationSumPos(candidates, target - candidates[i], i)
2. 如果有返回的结果就加上candidates[i]

例如:
candidates, target:
2367,7  [7] 加入到result
        2367,0  2367,-7
                236,-6
                23,-3
                2,-2
        236,1   236,-5
                23,-2
                2,-1
        23,4    23,1    23,-2
                        2,-1
                2,2 [2]加入到result
        2,5     2,3     2,1     2,-1
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //只用到end_pos index的candidates进行组合，和为target
    vector<vector<int>> combinationSumPos(vector<int>& candidates, int target, int end_pos){
        vector<vector<int>> result;
        vector<vector<int>> temp_result;
        int len_temp_result;
        int i;
        if (target < 0)
            return result;
        for (i = end_pos; i>= 0; --i){
            if (candidates[i] == target){
                result.push_back({candidates[i]});
            }
        }
        for (i = end_pos; i >= 0; --i){
            temp_result = combinationSumPos(candidates, target - candidates[i], i);
            len_temp_result = temp_result.size();
            for (int j = 0; j < len_temp_result; ++j){
                temp_result[j].push_back(candidates[i]);
                result.push_back(temp_result[j]);
            }
        }
        return result;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSumPos(candidates, target, candidates.size() - 1);
    }
};

void printVectorinVector(vector<vector<int>>& result){
    for(unsigned int i = 0; i < result.size(); ++i){
        for (unsigned int j = 0; j < result[i].size(); ++j){
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
}
int main(){
    vector<int> candidates;
    int target;
    vector<vector<int>> result;
    Solution sol;

    cout << "Expect: " << endl;
    result = {{7}, {2,2,3}};
    printVectorinVector(result);
    candidates = {2,3,6,7};
    target = 7;
    result = sol.combinationSum(candidates, target);
    cout << "Output: " << endl;
    printVectorinVector(result);

    cout << "Expect: " << endl;
    result = {{2,2,2,2}, {2,3,3}, {3,5}};
    printVectorinVector(result);
    candidates = {2,3,5};
    target = 8;
    result = sol.combinationSum(candidates, target);
    cout << "Output: " << endl;
    printVectorinVector(result);

    system("pause");
    return 0;

}