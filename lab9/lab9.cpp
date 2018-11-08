// lab9.cpp : Перегрузка
#include "pch.h"
#include <iostream>
/*
ПЕРЕГРУЗКА (Overloading)- объявление нескольких функций (а также методов классов и операторов, которые тоже явл-ся функциями) с одинаковыми именами, но разным набором аргументов.*/
/* matrix & operator += (matrix & second_matr) 
{
     for (int stroki=0; stroki < strok; stroki++)
	 {
	    for (int stolbs=0; stolbs < stolb; stolbs++)
	   {
           this -> setElem (i,j,first_matr [i][j] + second_matr.getElem(i,j))
		}
	 }

	return  (*this);
}
*/
//ЗАДАНИЕ
//Для класса матрицы определить операторы "+", "-" , "*", "<<"
//Они будут работать также и для унаследованного vec
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
	void transp();

	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << matr[i*columns + j] << "\t";
			}
			std::cout << std::endl;
		}
	};
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
			res.matr[i+j] = r.matr[i*l.columns+j]+l.matr[i*l.columns+j];
		}
	}
		return l;
	}
	

};
dynamic_matrix operator - (const dynamic_matrix & A, dynamic_matrix & B)
{
	
};
dynamic_matrix operator * (const dynamic_matrix & A, dynamic_matrix & B)
{
	/*if (columns == matr2.getRows())
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					int sum = 0;
					for (int k = 0; k < columns; k++) {
						sum += matr[i*columns + k] * matr2.getElem(k, j);
					}
					res[i*columns + j] = sum;
				}
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					cout << res[i*columns + j];
				}
				cout << endl;
			}
			return true;
		}
		else
		{
			cout << "col1 != row2";
			return false;
		}*/
};
dynamic_matrix operator << (const dynamic_matrix & A, dynamic_matrix & B)
{
	
}

int main()
{
	dynamic_matrix A, B;
	A.input(); A.print();
	B.input(); B.print();
	(A + B).print();

}
/*
class matrix
	{
	private:
		int * matr = new int[rows*columns];
		int rows, columns;
		int *res = new int[rows*columns];
	public:
		matrix();
		~matrix();

		bool summMatrix(matrix matr2);
		bool multMatrix(matrix matr2);

		int getElem(int row, int col);
		int getRows() {
			return rows;
		}
		int getColumns() {
			return columns;
		}

		bool input();
		void transp();

		void printM()
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					cout << matr[i*columns + j] << "\t";
				}
				cout << endl;
			}
		};
	};


	int main()
	{
		matrix matrA, matrB;
		matrA.input();
		matrB.input();
		matrA.printM();
		matrA.transp();
		matrA.summMatrix(matrB);
		matrA.multMatrix(matrB);
	}

	matrix::matrix() {}
	matrix::~matrix() {}

	bool matrix::summMatrix(matrix matr2)
	{
		if (rows == matr2.getRows() && columns == matr2.getColumns())
		{
			for (int i = 0 ; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					matr[i*columns + j] += matr2.getElem(i, j);
				}
			}
			printM();
			return true;
		}
		else {
			return false;
		}
	}

	void matrix::transp()
	{
		int t;
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout << matr[j * columns + i] << " ";
			}
			cout << endl;
		}
	}

	bool matrix::multMatrix(matrix matr2)
	{
		if (columns == matr2.getRows())
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					int sum = 0;
					for (int k = 0; k < columns; k++) {
						sum += matr[i*columns + k] * matr2.getElem(k, j);
					}
					res[i*columns + j] = sum;
				}
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					cout << res[i*columns + j];
				}
				cout << endl;
			}
			return true;
		}
		else
		{
			cout << "col1 != row2";
			return false;
		}
	}

	int matrix::getElem(int row, int col)
	{
		if (row < rows && col < columns && row > -1 && col > -1)
		{
			return matr[row*columns + col];
		}
		else
		{
			cout << "error";
			return -1;
		}
	}

	bool matrix::input()
	{
		cout << "rows=";
		cin >> rows;
		cout << "columns=";
		cin >> columns;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cin >> matr[i*columns + j];
			}
			cout << endl;
		}
		return true;
	}*/
