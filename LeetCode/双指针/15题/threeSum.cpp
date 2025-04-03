#include <vector>
#include <algorithm>
/*
题目：15. 三数之和
描述：
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a、b、c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：
答案中不可以包含重复的三元组

示例:
输入: nums = [-1,0,1,2,-1,-4]
输出: [[-1,-1,2],[-1,0,1]]
*/
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> result;
    int n = nums.size();
    if (n < 3) return result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // 跳过排序后出现的重复元素
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                // 跳过排序后出现的重复元素
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;

}