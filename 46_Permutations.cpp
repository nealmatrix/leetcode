//46. Permutations

/*Given a collection of distinct integers, return all possible permutations.*/

/*Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

/* Solution: recursion
1. 写好base case, 即len <= 1
2. 取nums[1:]，计算其permutation，注意cpp取slice要写成初始化的样子
3. 将nums[0]插入到step 2 permutation的各个位置，每个插入好的都push back到results中
   注意插入前要复制到另一个vector中，插入的位置的iterator是begin() + i, i in [0, len] 包含len
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> results;
        if (len <= 1){
            results.push_back(nums);
            return results;
        }
        int nums_0 = nums[0];
        vector<int> nums_res(nums.begin() + 1, nums.end()); //slice
        vector<vector<int>> results_res = permute(nums_res);

        vector<int> result_res_copy;
        for (const vector<int>& result_res : results_res){
            //插入的位置有最后len的，即插入到末尾
            for (unsigned int i = 0; i <= result_res.size(); ++i){ 
                result_res_copy = result_res; //每个插入前都copy一个，否则前面插入的会影响后面的
                result_res_copy.insert(result_res_copy.begin() + i, nums_0);
                results.push_back(result_res_copy);
            }
        }
        return results;
    }
};
void printVectorInVector(vector<vector<int>>& results){
    for (unsigned int i = 0; i < results.size(); ++i){
        for (unsigned int j = 0; j < results[i].size(); ++j){
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    Solution s;
    vector<int> nums;
    vector<vector<int>> results;
    
    cout << "Expect:\n[1,2,3],\n[1,3,2],\n[2,1,3],\n[2,3,1],\n[3,1,2],\n[3,2,1]" << endl;
    nums = {1,2,3};
    results = s.permute(nums);
    cout << "Output: "<<endl;
    printVectorInVector(results);

    system("pause");
}