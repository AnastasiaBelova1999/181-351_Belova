#include "stdafx.h"
#include <iostream>
#include "lib 351.h"
matrix::matrix()
{
}
matrix::~matrix()
{

}
int matrix::getStrok() {
	return strok;
};
int matrix::getStolb() {
	return stolb;
}
bool matrix::multiplication(int number)
{
	for (int stroki = 0; stroki < strok; stroki++)
	{
		for (int stolbs = 0; stolbs < stolb; stolbs++)
		{
			first_matr[stroki][stolbs] *= number;
		}
	}
	return true;
}
int matrix::getElem(int st, int sl) {
	if ((0 <= st < stolb) && (0 <= sl < strok)) {
		return first_matr[st][sl];
	}
	std::cout << "error";
	return -1;
}
bool matrix::transp()
{
	int time_matr[10][10] = { 0 };

	for (int stroki = 0; stroki < strok; stroki++)
	{
		for (int stolbs = 0; stolbs < stolb; stolbs++)
		{
			time_matr[stolbs][stroki] = first_matr[stroki][stolbs];
		}
	}
	delete[] first_matr;
	first_matr = new int*[stolb];
	for (int i = 0; i < stolb; i++)
	{
		first_matr[i] = new int[strok];
	}
	for (int stroki = 0; stroki < stolb; stroki++)
	{
		for (int stolbs = 0; stolbs < strok; stolbs++)
		{
			first_matr[stroki][stolbs] = time_matr[stroki][stolbs];
		}

	}

	int c = stolb;
	stolb = strok;
	strok = c;
	return true;
}
bool matrix::correx(int a, int b) {
	if ((1 <= a <= 10) && (1 <= b <= 10))
	{
		return true;
	}
	return false;
};
bool matrix::print() {
	std::cout << "\n";
	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			std::cout << first_matr[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "__________________________________________" << "\n";
	return true;
}
bool matrix::input() {
	int stroki;
	int stolbs;
	std::cout << "input number of lines ";
	std::cin >> stroki;
	std::cout << "input number of rows ";
	std::cin >> stolbs;
	if (!correx(stroki, stolbs)) {
		std::cout << "wrong";
		return false;
	}
	first_matr = new int*[stroki];
	for (int i = 0; i < stroki; i++)
	{
		first_matr[i] = new int[stolbs];
	}
	for (int i = 0; i < stroki; i++)
	{
		for (int j = 0; j < stolbs; j++)
		{
			std::cout << "input element " << (i + 1) << " " << (j + 1) << "\t";

			std::cin >> first_matr[i][j];

			std::cout << "\n";
		}
		stolb = stolbs;
		strok = stroki;
	};
}
bool matrix::summMatrix(matrix math2) {

	if ((strok != math2.strok) || (stolb != math2.stolb)) {
		return false;
	}
	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			first_matr[i][j] += math2.first_matr[i][j];
		}
	}
	return true;

};
bool matrix::multMatrix(matrix math2) {
	if (stolb != math2.strok) {
		return false;
	};
	int time_matr1[10][10] = { 0 };
	int c = 0;
	int b = 0;
	for (int strok1 = 0; strok1 < strok; strok1++)
	{

		for (int stolb2 = 0; stolb2 < stolb; stolb2++)
		{
			for (int Summ = 0; Summ < stolb; Summ++)
			{
				b = math2.first_matr[strok1][Summ];
				c += first_matr[strok1][Summ] * b;
			}

			time_matr1[strok1][stolb2] = c;
			c = 0;
		}
	}
	delete[] first_matr;
	first_matr = new int*[strok];
	stolb = math2.stolb;
	for (int i = 0; i < stolb; i++)
	{
		first_matr[i] = new int[strok];
	}
	for (int stroki = 0; stroki < strok; stroki++)
	{
		for (int stolbs = 0; stolbs < stolb; stolbs++)
		{
			first_matr[stroki][stolbs] = time_matr1[stroki][stolbs];
		}
	}

	return true;
}