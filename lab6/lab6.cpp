#include "pch.h"
#include <iostream>

//Наследование. Заимствование. Свойства методов родительского класса в производном классе.
//1.ОПРЕДЕЛЕНИЕ И СИНТАКСИС
//СИНТАКСИС:
//class имя_произв_класса: [тип_наследования] имя_родительского_класса1,
//В род.В заголовке при наследовании
//классе			public:			protected:		 private:
//public			public:			protected:		 private:
//protected		    protected:		protected:		 private:
//private			недоступно		недоступно		 недоступно
//2.Метод, переопределенный в дочерним классе полностью заменит унаследованный родительский метод
//Чтобы при запуске нового дочернего метода также выполнять и родительский необходимо указать явно
//в родительском классе void weapon::reload(){};
//в дочернем классе void rifle:: reload():weapon::reload(), ... {};
//3.Если объявить метод со словом virtual, в данном классе можно не проводить реализацию метода,
//и определить его (привести реализацию) только в дочерних классах
//4.void fnc1(const тип1 параметр1, тип 2 параметр2)
//{
// Параметр1=10;
//}
//Объявление константого метода класса запрещает ему менять какое-либо из свойств объекта
//                                             \/
//void fnc1( тип1 параметр1, тип 2 параметр2) const
//{
// Параметр1=10;
//}
//4* Приведение типов
//При попытке сложить/умножить/вычесть/разделить
//int i = -15;
//double d = 1000.5e+03; // = 1000.5 * 10^3 = 1000.5 * pow(10, 3) = 1000500 = 1000.5e03
//float result1;
//long long result2;
//result1 = i + d;
//result2 = i / d;
//const char *ch1 = "123"; // {'1', '2', '3', 0} = {'1', '2', '3', '\0'}
//const char *ch2 = "456";
//? ? ? = ch1 + ch2;
//std::string "1233456"
//getchar();
//return 0;

class matrix
{
private:
	double matr[10][10];
	int rows;
	int columns;
public:
	matrix();
	~matrix();
	bool input();
	bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		return -1;
		std::cout << "Connot get element.Index Error!\n";
		return -1;
	}
};
class vector
{
private:
	int vec[10];
	int n;
	double matr[10][10] = { {0} };

public:
	int getN() { return n; }
	int getEl(int n);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			std::cout << vec[i] << ' ';

		}
	};
	bool multvec(vector vec2);
};



int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.transp();
	matrA.print();
	matrA.summMatrix(matrB);


}

matrix::matrix()
{
	
}

matrix::~matrix()

{
}



bool matrix::input()
{
	std::cin >> rows;
	if (rows < 1 || rows>10)
		return false;
	std::cin >> columns;
	if (columns < 1 || columns > 10)
		return false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i][j];
		}
	}
	return true;
}
bool matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
	return true;
}
bool matrix::summMatrix(matrix matr2)
{
	double result[10][10];
	if ((rows == matr2.getRows()) && (columns == matr2.getColumns()))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[i][j] = matr[i][j] + matr2.getElem(i, j);
			}
		}
		return true;
	}
	else return false;
}
bool matrix::multMatrix(matrix matr2)
{
	double matr3[10][10];
	if (columns == matr2.getRows()) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < columns; j++) {
				for (int k = 0; k < columns; k++) {
					matr3[i][j] = matr[i][k] * matr2.getElem(k, j);
				}
			}
		}
		return true;
	}
	else return false;
}

bool matrix::transp()
{
	int ch;
	if (rows != columns) {
		ch = rows;
		rows = columns;
		columns = ch;
	}
	int t;//t-временная переменная;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			t = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = t;
		}
	}
	return true;
}
int vector::getEl(int n)
{
	if (n < 11 && n > 0) { return vec[n]; }
	else
	{
		std::cout << "error";
		return -1;
	}
}

bool vector::enter()
{
	std::cout << "n=";
	std::cin >> n;
	if (n < 1 || n > 10) { return false; }
	for (int j = 0; j < n; j++)
	{
		std::cout << "vec[" << j << "]=";
		std::cin >> vec[j];
	}
	return true;
}

bool vector::multvec(vector vec2)
{
	int scal = 0;
	if (n = vec2.getN()) {
		for (int i = 0; i < n; i++)
		{
			scal += vec[i] * vec2.getEl(i);
		}
		std::cout << scal;
	}
	else { return false; }
}

