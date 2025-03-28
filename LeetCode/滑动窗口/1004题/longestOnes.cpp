#include <vector>
using namespace std;

/*
题目描述
给定一个二进制数组 nums 和一个整数 k，你可以将最多 k 个 0 翻转为 1，返回数组中最大连续 1 的个数。
示例
输入：nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
输出：6
解释：将后两个 0 翻转为1，最长连续1的子数组为 [1,1,1,0,0,1,1,1,1,1]（索引4到9）

*/

int longestOnes(vector<int>& nums, int k) {
	int zeorNum = 0;
	int left = 0;
	int maxNum = 0;
	for (int right = 0; right < nums.size(); right++)
	{
		if (nums[right] == 0)
			zeorNum++;
		while (zeorNum > k)
		{
			if (nums[left] == 0)
				zeorNum--;
			left--;
		}
		maxNum = max(maxNum, right - left + 1);
	}
}