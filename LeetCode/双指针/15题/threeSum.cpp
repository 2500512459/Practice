#include <vector>
#include <algorithm>
/*
��Ŀ��15. ����֮��
������
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 �������ҳ����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣

ע�⣺
���в����԰����ظ�����Ԫ��

ʾ��:
����: nums = [-1,0,1,2,-1,-4]
���: [[-1,-1,2],[-1,0,1]]
*/
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> result;
    int n = nums.size();
    if (n < 3) return result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // �����������ֵ��ظ�Ԫ��
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                // �����������ֵ��ظ�Ԫ��
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