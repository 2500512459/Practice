/*
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵtarget�����������������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸣������㲻��ʹ��������ͬ��Ԫ�ء�
����԰�����˳�򷵻ش𰸡�
ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
ʾ�� 2��
���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��
���룺nums = [3,3], target = 6
�����[0,1]
��ʾ��
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
ֻ�����һ����Ч��
���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ����д����û�п��ǵ��ظ������
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            map<int, int> myMap;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                myMap[nums[i]] = i;
            }
            for (auto it = myMap.begin(); it != myMap.end(); ++it) {
                if(myMap.find(target - it->first) != myMap.end())
                {
                    result.push_back(it->second);
                    result.push_back(myMap[target - it->first]);
                    break;
                }
            }
            return result;
        }
};
// ��ȷд����ÿ�δ���Ԫ��ǰ���ж��Ƿ��Ѵ�����һ��Ԫ��
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            map<int, int> myMap;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                int complement = target - nums[i];
                if(myMap.find(complement) != myMap.end())
                {
                    result.push_back(myMap[complement]);
                    result.push_back(i);
                    break;
                }
                myMap[nums[i]] = i;
            }
            return result;
        }
};
