/*
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
ͬʱ������ nums[i] + nums[j] + nums[k] == 0 �����㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
ʾ�� 1��
���룺nums = [-1,0,1,2,-1,-4]
�����[[-1,-1,2],[-1,0,1]]
���ͣ�
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 ��
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 ��
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 ��
��ͬ����Ԫ���� [-1,0,1] �� [-1,-1,2] ��
ע�⣬�����˳�����Ԫ���˳�򲢲���Ҫ��
ʾ�� 2��
���룺nums = [0,1,1]
�����[]
���ͣ�Ψһ���ܵ���Ԫ��Ͳ�Ϊ 0 ��
ʾ�� 3��
���룺nums = [0,0,0]
�����[[0,0,0]]
���ͣ�Ψһ���ܵ���Ԫ���Ϊ 0 ��
��ʾ��
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
        sort(nums.begin(), nums.end());  // �ؼ���һ��������
        
        for (int i = 0; i < nums.size(); i++) {
            // ȥ�أ������ظ��Ĺ̶�Ԫ��
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1;            // ��ָ����ʼλ��
            int right = nums.size() - 1; // ��ָ����ʼλ��
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum < 0) {          // ��̫С����ָ������
                    left++;
                } else if (sum > 0) {   // ��̫����ָ������
                    right--;
                } else {                // �ҵ���Ч���
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // ȥ�أ���������ظ�Ԫ��
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // ȥ�أ������Ҳ��ظ�Ԫ��
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;  // �ƶ�����һ����Ԫ��
                    right--; // �ƶ�����һ����Ԫ��
                }
            }
        }
        return res;
    }
};