#pragma once
class matrix
{
private:
	int **first_matr;
	int stolb;
	int strok;
public:
	bool correx(int a, int b);
	virtual bool input();
	virtual bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	int getElem(int st, int sl);
	bool transp();
	int getStrok();
	int getStolb();
	virtual bool multiplication(int number);
	matrix();
	~matrix();
};