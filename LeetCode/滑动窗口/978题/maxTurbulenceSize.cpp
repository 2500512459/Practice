#include <vector>
#include <algorithm>
using namespace std;
/*
978�⣬��Ŀ������������� ����һ���������� arr������ arr �� �������������ĳ��ȡ�

��������������ʱ�����ǳ������� arr[i...j] Ϊ���������飺

���� i <= k < j��
��� k Ϊ��������ô arr[k] > arr[k+1]
��� k Ϊż������ô arr[k] < arr[k+1] ����
���� i <= k < j��
��� k Ϊ��������ô arr[k] < arr[k+1]
��� k Ϊż������ô arr[k] > arr[k+1]
�����������������Ԫ�ؽ�������ϸ�������ϸ�ݼ������ԣ�

ʾ�� 1
���룺arr = [9,4,2,10,7,8,8,1,9]
�����5
���ͣ���������������� [4,2,10,7,8]������Ϊ 5
ʾ�� 2��
���룺arr = [4,8,12,16]
�����2
���ͣ������� [4,8] �� [8,12] �ȣ����Ⱦ�Ϊ 2
*/
vector<int> maxTurbulenceSize(vector<int>& arr) {
    if (arr.size() == 1) return 1;
    
    int max_len = 1;
    int left = 0;
    int right = 0;
    vector<int>& arr_max;
    for(init i = 0; i < arr.size(); ++i)
    {
        if (left == right) {
            // ����ÿ���ƶ��󴰿�ʱ���Ҵ�����һ������
            if (arr[right] == arr[right + 1]) left++; // �����ͬ������
            right++;
        } 
        else
        {
            //ֻҪ��ǰ�Ҵ������ڵ�Ԫ��������Ԫ�أ����Ҵ�������
            if((arr[right-1] < arr[right] && arr[right] > arr[right+1]) || 
            (arr[right-1] > arr[right] && arr[right] < arr[right+1])) 
            {
                right++;
            }
            else
            {
                left = right;
            }
        } 
        max_len = max(max_len, right - left + 1);
    }
    for(int i = left; i < right; ++i)
    {
        arr_max.push_back(arr[i]);
    }
    
    return arr_max;
}