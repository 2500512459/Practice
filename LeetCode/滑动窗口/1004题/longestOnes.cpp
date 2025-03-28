#include <vector>
using namespace std;

/*
��Ŀ����
����һ������������ nums ��һ������ k������Խ���� k �� 0 ��תΪ 1������������������� 1 �ĸ�����
ʾ��
���룺nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
�����6
���ͣ��������� 0 ��תΪ1�������1��������Ϊ [1,1,1,0,0,1,1,1,1,1]������4��9��

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