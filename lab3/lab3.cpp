// lab3.cpp : функции

#include "pch.h"
#include <iostream>
void bubble(int array[10])
{
	int tem; //временная переменная для обмена элементов местами
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tem = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tem;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << array[i] << "\t";
		}
	}
}
void caesar(char str[10])
{
     int sum = 3;
     int t = 0;
      for (int i = 0; i < 10; i++) 
	  {
	      t = str[i] + sum;
	      str[i] = char(t);
       }
	  for (int i = 0; i < 10; i++)
	  {
		  std::cout << str[i] << "\t";
	  }
}

int main()
{
	int bub[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << "insert the number";
		std::cin >> bub[i];
	}
	std::cout << '\n';
	bubble(bub);
	std::cout << '\n';
	char str[10];
	for (char i= 0; i < 10; i++)
	{
		std::cout << "enter 10 characters ";
		std::cin >> str[i];
	}
	std::cout << '\n';
	caesar(str);
	return(0);
	
		

}


