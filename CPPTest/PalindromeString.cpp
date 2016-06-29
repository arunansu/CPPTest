#include "stdafx.h"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

string longestPalindrome(string a)
{
	string palindrome = "";

	if (a.length() > 0)
	{
		palindrome = a[0];
	}

	for (string::size_type i = 0; i < a.length(); i++)
	{
		for (string::size_type j = 0; j < i; j++)
		{
			string substr = a.substr(j, i + 1);
			if (substr == string(substr.rbegin(), substr.rend()))
			{
				if (substr.length() > palindrome.length())
				{
					palindrome = substr;
				}
			}
		}
	}
	return palindrome;
}

int main()
{
	cout << longestPalindrome("abafgdfgfjracecar") << endl;
	cout << longestPalindrome("abcdefg") << endl;
	cout << longestPalindrome("Anna is taking the kayak to the river") << endl;
	getchar();
	return 0;
}