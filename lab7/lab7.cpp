// lab7.cpp : динамическое выделинение памяти
//
#include "pch.h"
#include <iostream>
/*
	int arr[11][12] = {0};  - в таком объявлении только константные размерности
	стековая память ограничена, при неправильном использовании стек переполняется (stack overflow)
	размерности массивов, выделяемых в стековой памяти, фиксированы и задаются константами
	int b[1000][1000] = {0} ; - переполнение стека
	для использования свободной памяти ОС (heap - куча_)
	объявляются динамические переменные по синтаксису
	указатель_на_тип_ имя_переменной = new тип;
	или тип *имя_переменной = new тип;
	работа с динамической памятью происходит через указатели
	Преимущества:
	1. доступно гораздо больше памяи, нежели в стеке
	2. размеры массивов и структур данных можно определять и менять во время работы приложения
	Особенность:
	Если приложение предназначено для длительной работы,
	во избежание переполнения памяти созданные переменные и блоки памяти после испльзования
	должны быть освобождены с помощью оператора delete:
	delete имя_переменной;

	int * ptr_int = new int; // в неопределенной памяти создается блок
	// размером с int и указатель на него возвращается в переменную ptr_int
	// вызов утечки памяти
	for (int i = 0; i < 1000; i++)
	{
		long long * b = new long long;
		/*
		1. каждый заход в стеке создается новый указатель
		2. выделяется блок new long long; в куче (нераспределенной памяти), приписанной к этой программе
		3. стековая переменная b исчезает
		4. а блок по-прежнему остается там же
		5. при следующем заходе выделяется новый блок// совершать нужные действия  с переменной

		delete b; // удалить блок памяти пока не потерян указатель на нее
	}
	// пара операторов new/delere -  это одно из нововведений с++ относительно С
	 в динамической памяти могут выделяться только одномерные массивы
	тип * имя_указателя = new типь [длина];
	удаляются одномерные массивы с помощью записи
	delete [] имя_указателя
	*/

	/*  int * matr = new int[11 * 12];
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			matr[row * 11 + col] = row * 11 + col;
		}
	}
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			std::cout << matr[row * 11 + col] << "\t";
		}
	}
}
*/
#include "pch.h"
#include <iostream>

class dynamic_matrix
{
private:
	int rows;
	int columns;
	double *matr;
public:
	dynamic_matrix();
	~dynamic_matrix();

	bool input();
	bool print();
	bool summMatrix(dynamic_matrix matr1);
	bool multMatrix(dynamic_matrix matr1);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	/*double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Cannot get element. Index Error!\n";
		return	-1;
	}*/
};

dynamic_matrix::dynamic_matrix()
{
}

dynamic_matrix::~dynamic_matrix()
{
}

bool dynamic_matrix::input()
{
	std::cout << "Insert rows";
	std::cin >> rows;
	std::cout << "Insert columns";
	std::cin >> columns;
	std::cout << "Insert matrix's elements";
	matr = new double[rows * columns];
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

bool dynamic_matrix::summMatrix(dynamic_matrix matr1)
{
	if ((rows == matr1.rows) && (columns == matr1.columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i * columns + j] += matr1.matr[i * columns + j];
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}

bool dynamic_matrix::multMatrix(dynamic_matrix matr1)
{
	if (rows == matr1.columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				double mid = 0;
				for (int k = 0; k < rows; k++)
				{
					mid += matr[i * rows + k] * matr1.matr[k * rows + j];
				}
				matr[i * rows + j] = mid;
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}

bool dynamic_matrix::transp()
{
	int ch;
	if (rows != columns)
	{
		ch = rows;
		rows = columns;
		columns = ch;
	}
	double sw = 0;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			sw = matr[i * columns + j];
			matr[i * columns + j] = matr[j * columns + i];
			matr[j * columns + i] = sw;
		}
	}
	std::cout << std::endl << "Done" << std::endl;
	return true;
}



int main()
{
	dynamic_matrix matrA, matrB;
	matrA.input();
	//matrB.input();
	matrA.print();	matrA.transp();

	//matrA.summMatrix(matrB);
	//matrA.print();
	//matrA.multMatrix(matrB);
	matrA.print();
	return 0;




