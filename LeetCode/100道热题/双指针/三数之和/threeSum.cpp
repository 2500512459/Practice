/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
提示：
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());  // 关键第一步：排序
        
        for (int i = 0; i < nums.size(); i++) {
            // 去重：跳过重复的固定元素
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1;            // 左指针起始位置
            int right = nums.size() - 1; // 右指针起始位置
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum < 0) {          // 和太小，左指针右移
                    left++;
                } else if (sum > 0) {   // 和太大，右指针左移
                    right--;
                } else {                // 找到有效组合
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // 去重：跳过左侧重复元素
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // 去重：跳过右侧重复元素
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;  // 移动到下一个新元素
                    right--; // 移动到下一个新元素
                }
            }
        }
        return res;
    }
};