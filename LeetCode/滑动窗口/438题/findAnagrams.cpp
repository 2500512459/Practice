#include <vector>
#include <map>
using namespace std;

/*
��Ŀѡ��438. �ҵ��ַ�����������ĸ��λ��

��Ŀ������
���������ַ��� s �� p���ҵ� s ������ p �� ��ĸ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ������
��ĸ��λ��ָ��ĸ��ͬ�����в�ͬ���ַ�����

����: s = "cbaebabacd", p = "abc"
���: [0,6]
����: ��ʼ���� 0 ���Ӵ� "cba" �� "abc" ����λ�ʣ����� 6 ���Ӵ� "bac" Ҳ����λ�ʡ�
*/

//ͬ567�����ƣ�ÿ���ƶ��������ں�Ŀ���ж�һ�¾���
vector<int> findAnagrams(string s, string p)
{
	vector<int> value;
	if (s.size() < p.size())
		return value;

	vector<int> target(26, 0);//Ŀ��
	vector<int> window(26, 0);//��������

	//��ȡĿ��
	for (char c : p)
	{
		target[c - 'a']++;
	}
	//��ʼ������
	for (int i = 0; i < p.size(); ++i)
	{
		window[s[i] - 'a']++;
	}

	if (target == window)
		value.push_back(0);

	for (int i = p.size(); i < s.size(); i++)
	{
		window[s[i - p.size()] - 'a']--;
		window[s[i] - 'a']++;
		if (window == target)
			value.push_back(i - p.size() + 1);
	}
	return value;
}