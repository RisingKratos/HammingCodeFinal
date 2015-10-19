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
		t *= 2;                 // int c выведет нам минимальный k из всех решений неравенства 2^k+1>m
		c++;
	}
	t = 1;

	while (t <= s.size())
	{
		s.insert(s.size() - t + 1, "0");   // добавляем нули 
		t *= 2;
	}

	for (double i = 0; i< c + 1; ++i)
	{
		t = 0; 
		int j = 0;
		while (t < s.size())
		{
			int y = 0;                        // у будет означать длину шагов в таблице
			while (y < i + 1)				  // например, для р1 оно равно 1, для р2 у=2, и тд.
			{
				if (s[y] == '1') 
				{
					++j;					  // если сумма "р" будет нечетным, мы должны будем вместо него в стринге записать 1
				}         
				++y;
			}

			t += y;							  //пропускаем "у" клеток
		}
		int k = 0, l = 1;					  // "l" показывает на адрес, значение которого мы должны будем изменить 
		if (i != 0)
			while (k < i) 
			{ 
				l *= 2;						  // адрес на которую указывает "р(i+1)" 
				++k; 
			}	  
		if (j % 2 == 1) s[s.size() - l] = '1';
	}
	cout << s << endl;
	return 0;
}