#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	vector<int> v;

	for (int i = 0; i < s.length();++i)
	{
		int x = (int)s[i] - 48;
		v.push_back(x);
	}

	int t = 2, m = s.size(), c = 0;

	while (t + 1 <= m)
	{
		t *= 2;                 // int c ������� ��� ����������� k �� ���� ������� ����������� 2^k+1>m
		c++;
	}
	t = 1;

	while (t <= s.size())
	{
		s.insert(s.size() - t + 1, "0");   // ��������� ���� 
		t *= 2;
	}

	for (double i = 0; i< c + 1; ++i)
	{
		t = 0; 
		int j = 0;
		while (t < s.size())
		{
			int y = 0;                        // � ����� �������� ����� ����� � �������
			while (y < i + 1)				  // ��������, ��� �1 ��� ����� 1, ��� �2 �=2, � ��.
			{
				if (s[y] == '1') 
				{
					++j;					  // ���� ����� "�" ����� ��������, �� ������ ����� ������ ���� � ������� �������� 1
				}         
				++y;
			}

			t += y;							  //���������� "�" ������
		}
		int k = 0, l = 1;					  // "l" ���������� �� �����, �������� �������� �� ������ ����� �������� 
		if (i != 0)
			while (k < i) 
			{ 
				l *= 2;						  // ����� �� ������� ��������� "�(i+1)" 
				++k; 
			}	  
		if (j % 2 == 1) s[s.size() - l] = '1';
	}
	cout << s << endl;
	return 0;
}