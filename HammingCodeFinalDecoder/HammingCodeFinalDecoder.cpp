#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <string.h>

using namespace std;

void HammingCheck(char *hamming_string, int parity)
{
			int length, num_parity, i, j, start, k;
			int error_bit = 0;
			length = strlen(hamming_string);
			num_parity = ceil(log(length) / log(2));
			for (i = 0; i < num_parity; i++) 
			{
					start = pow(2, i);
					int check_parity = parity;
					for (j = start; j < length; j = (2 * start)) 
					{
							for (k = j; (k < ((2 * j) - 1)) && (k < length); k++) 
							{	
									check_parity ^= (hamming_string[length - k] - '0');
							}//end for k
						
					}//end for j
					error_bit = error_bit + (check_parity*start);
			}//end for i
			if (error_bit == 0)
				cout<<"No error \n";
			else 
			{
				cout << "There is an error in bit: " << error_bit;
				if (hamming_string[length - error_bit] == '0')
					hamming_string[length - error_bit] = '1';
				else
					hamming_string[length - error_bit] = '0';
				cout << "The corrected Hamming code is: " << hamming_string << endl;
			}

}

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != '0' && s[i] != '1')
		{
			cout << endl << "Invalid code" << endl;
			return 0;
		}

	}
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
	for (int i = 0; i < s.length(); i += 2)
	{
		p1 += s[i];
	}

	for (int i = 1; i < s.length(); i +=3)
	{
		p2 += s[i] + s[i + 1];
	}

	for (int i = 1; i < s.length(); i *= 2)
	{
		s[s.length() - i] = '2';
	}

	string fixed;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != '2')
		{
			fixed.push_back(s[i]);
		}
	}

	cout << fixed << endl;

	char *Hamming = new char[s.length()];

	for (int i = 0; i < s.length();++i)
	{
		Hamming[i] = s[i];
	}

	HammingCheck(Hamming, 0);

	return 0;
}