/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
��ע�� �������ڲ���������������ԭ�ض�������в�����
ʾ�� 1:
����: nums = [0,1,0,3,12]
���: [1,3,12,0,0]
ʾ�� 2:
����: nums = [0]
���: [0]
��ʾ:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
���ף����ܾ���������ɵĲ���������
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[pos++]);
            }
        }
    }
};