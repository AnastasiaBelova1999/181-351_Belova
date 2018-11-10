#include "stdafx.h"
#include <iostream>
#include "lib 351.h"


int func1(double p1, char p2)
{
	return p1+p2;
}
class dynamic_matrix
{
private:
	int rows;
	int columns;
	int *matr;
public:
	dynamic_matrix();
	~dynamic_matrix();
	bool summMatrix(dynamic_matrix matr2);
	bool multMatrix(dynamic_matrix matr2);
	int getElem(int row, int col);
	int getRows() {
		return rows;
	}
	int getColumns() {
		return columns;
	}

	bool input();
	bool print();
	void transp();

	friend dynamic_matrix operator + (const dynamic_matrix & A, dynamic_matrix & B);
	friend dynamic_matrix operator - (const dynamic_matrix & A, dynamic_matrix & B);
	friend dynamic_matrix operator * (const dynamic_matrix & A, dynamic_matrix & B);
	friend dynamic_matrix operator << (const dynamic_matrix & A, dynamic_matrix & B);
};

dynamic_matrix::dynamic_matrix()
{

};
dynamic_matrix:: ~dynamic_matrix()
{

};
dynamic_matrix operator + (const dynamic_matrix & r, dynamic_matrix & l)
{
	if (r.rows == l.rows && l.columns == r.columns)
	{
		dynamic_matrix res;
		res.columns = r.columns;
		res.rows = l.rows;
		//res.matr = new double[res.rows * res.columns];
		for (int i = 0; i < r.rows; i++)
		{
			for (int j = 0; j < l.columns; j++)
			{
				res.matr[i + j] = r.matr[i*res.columns + j] + l.matr[i*res.columns + j];
			}

		}
		return res;
	}

	else
		return l;
};
dynamic_matrix operator - (const dynamic_matrix & r, dynamic_matrix & l)
{
	if (r.rows == l.rows && l.columns == r.columns)
	{
		dynamic_matrix res;
		res.columns = r.columns;
		res.rows = l.rows;
		//res.matr = new double[res.rows * res.columns];
		for (int i = 0; i < r.rows; i++)
		{
			for (int j = 0; j < l.columns; j++)
			{
				res.matr[i + j] = r.matr[i*res.columns + j] - l.matr[i*res.columns + j];
			}

		}
		return res;
	}

	else
		return l;

};
dynamic_matrix operator * (const dynamic_matrix & l, dynamic_matrix & r)
{
	if (r.columns == l.rows)
	{
		dynamic_matrix res;
		res.columns = r.columns;
		res.rows = l.rows;
		res.matr = new int[res.rows * res.columns];
		for (int i = 0; i < l.rows; i++)
		{
			for (int j = 0; j < r.columns; j++)
			{
				int sum = 0;
				for (int k = 0; k < r.columns; k++)
				{
					sum += l.matr[i * l.rows + k] * r.matr[k * l.rows + j];
					res.matr[i*l.rows + j] = sum;
				}
			}
		}
		for (int i = 0; i < l.rows; i++)
		{
			for (int j = 0; j < r.columns; j++)
			{
				std::cout << res.matr[i*r.columns + j];
			}
			std::cout << std::endl << "Done" << std::endl;
			return res;
		}
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return l;
	}

};
 /*std::ostream & operator << (std::ostream & os, dynamic_matrix & r)
{
	for (int i = 0; i < r.rows; i++)
	{
		for (int j = 0; j < l.columns; j++)
		{
			os << r.matr[i * r.columns + j] << ' ';
		}
		os << std::endl;
	}
	return os;
}*/
bool dynamic_matrix::input()
{
	std::cout << "Insert rows";
	std::cin >> rows;
	std::cout << "Insert columns";
	std::cin >> columns;
	std::cout << "Insert matrix's elements";
	matr = new int[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j];
		}
	}
	std::cout << std::endl << "Done";
	return true;
}
bool dynamic_matrix::print()
{
	std::cout << std::endl << "Printing matrix... \n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matr[i * columns + j] << ' ';
		}
		std::cout << std::endl;
	}
	return true;
}
