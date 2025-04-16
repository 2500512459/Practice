
/*
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
ʾ�� 1��
���룺nums = [100,4,200,1,3,2]
�����4
���ͣ���������������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
ʾ�� 2��
���룺nums = [0,3,7,2,5,8,4,6,0,1]
�����9
ʾ�� 3��
���룺nums = [1,0,1,2]
�����3
��ʾ��
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//�ҿ�ʼ��û���뵽ʹ��set��������Ҫʹ��map������������ʾ��֪��
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set(nums.begin(), nums.end());
        int max_len = 0;
    
        for (int num : num_set) {
            // ֻ�е�num���������е����ʱ����num-1���ڼ����У����Ž��к�������
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int current_len = 1;
            
                // ������������Ԫ��
                while (num_set.count(current_num + 1)) {
                    current_num++;
                    current_len++;
                }   
            
                max_len = max(max_len, current_len);
            }
        }
        return max_len;
    }
};