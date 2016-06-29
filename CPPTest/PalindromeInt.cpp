#include "stdafx.h"
#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
	if (n / 10 == 0) return true;
	else
	{
		int last = n % 10;
		int i = 10;
		while (n / i > 0)
		{
			i = i * 10;
		}
		int first = n * 10 / i;
		if (last == first)
		{
			return isPalindrome((n - first * i / 10 - last)/10);
		}
		else return false;

	}

}

int mainPalindromeInt()
{
	cout << isPalindrome(100) << endl;
	cout << isPalindrome(10101) << endl;
	cout << isPalindrome(1212121);
	getchar();
	return 0;
}