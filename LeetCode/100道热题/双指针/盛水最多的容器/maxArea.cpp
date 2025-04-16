/*
����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��
�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
�����������Դ�������ˮ����
˵�����㲻����б������
ʾ�� 1��
���룺[1,8,6,2,5,4,8,3,7]
�����49 
���ͣ�ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ�����ֵΪ 49��
ʾ�� 2��
���룺height = [1,1]
�����1
��ʾ��
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��ֻ�뵽�� ��������ʱ�临�Ӷ�O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int area = (j - i) * min(height[i], height[j]);
                maxArea = max(maxArea, area);
            }
        }
    }
};
// ���Ϊ˫ָ�뷨��ʱ�临�Ӷ�O(n)
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int max_area = 0;
            int left = 0;
            int right = height.size() - 1;
            
            while (left < right) {
                int current_height = min(height[left], height[right]);
                int current_width = right - left;
                max_area = max(max_area, current_height * current_width);
                
                // �ƶ��϶̱ߵ�ָ����Ѱ�Ҹ���߶�
                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            
            return max_area; // ԭ����ȱ�ٷ������
        }
    };