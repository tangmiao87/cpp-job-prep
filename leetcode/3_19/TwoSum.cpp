#include <iostream>   // 输入输出
#include <vector>     // 向量容器（存储数组）
#include <unordered_map>  // 哈希表

using namespace std;  // 简化代码，新手友好

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_Map;  // 键：数组值，值：数组下标
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];  // 计算需要找的补数
            // 如果补数存在于哈希表中，返回补数下标和当前下标
            if(num_Map.find(complement) != num_Map.end()){
                return {num_Map[complement], i};
            }
            // 否则将当前值和下标存入哈希表
            num_Map[nums[i]] = i;
        }
        return {};  // 无结果时返回空数组
    }
};

// 仅保留一个 main 函数（程序入口）
int main(){
    // 测试用例：数组 [2,7,11,15]，目标值 9，预期结果 [0,1]
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    // 调用 twoSum 函数
    vector<int> result = solution.twoSum(nums, target);
    
    // 输出结果
    if (!result.empty()) {
        cout << "两个数的下标：[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "未找到满足条件的两个数" << endl;
    }

    return 0;
}
