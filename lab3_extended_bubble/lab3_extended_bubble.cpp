

#include "pch.h"
#include <iostream>

int main()
{
	int bubble[10]{ 8, 4, 6, 5, 7, 0, 2, 3, 1, 9};
	int tem;//временная переменная для обмена элементов местами
	int max = 10;
	int min = 1;
	int k = max - 1;
	for (int i = 0; i < 5; i++)
	{
		for (int i = k; i >= min; i--)
		{
			if (bubble[i - 1] > bubble[i])
			{
				tem = bubble[i - 1];
				bubble[i - 1] = bubble[i];
				bubble[i] = tem;
			}
		}
		min++;
		for (int i = min; i <= k; i++)
		{
			if (bubble[i - 1] > bubble[i])
			{
				tem = bubble[i];
				bubble[i] = bubble[i - 1];
				bubble[i - 1] = tem;
			}
		}
	}
         k--; 
	for (int i = 0; i < 10; i++)
	{
		std::cout << bubble[i] << "\t";
	}
	return 0;
}


	