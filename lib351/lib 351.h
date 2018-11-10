#pragma once
#include <ostream>
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
