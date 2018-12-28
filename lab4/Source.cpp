// lab4.cpp : ���������
//
#include <iostream>

/* ��������� - ����������, �������� �����(��������) �����-���� ������
���������� � ����������� ������(pointer)
ptr_a, ptr_b.
1. ��������� �����������, ��� ������� ���������� � ����������� ���������
���_������ * ���_��������� int * ptr_a
ptr_a = &a ������� �������� & ��������� - �������� ��������� ������
���������� ��������� ��� unsigned int ��� insigned long long,
��� ��� ������������� ������� ���.
2. ������ ���������
��� ��������� ������ ����� � ��� �� ����������� (�������)
����� �� �� ��� �������� ��� ������ (������, ������, ������)
��������� �� ���� ������ ����� �������� 4/8 ����, ��� � �������� ��������
������������� ����������.
3. ���������� ���������
���_���������
*/

int main()

{

	int arr1[10] = { 5, 9, 45, 17, 15 };

	int a;

	double dbl;

	int * ptr_int = &a;

	double * ptr_double = &dbl;

	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "double pointer size = " << sizeof(ptr_double) << std::endl;
	std::cout << "char pointer size = " << sizeof(char*) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long*) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool*) << std::endl;

	//���������� ����������

	std::cout << "ptr_int = " << ptr_int << std::endl;
	std::cout << "ptr_double = " << ptr_double << std::endl;
	std::cout << std::endl << "ptr_int = 0x" << std::hex << ptr_int << std::endl;

	std::cout << "arr = " << arr1 << std::endl;
	std::cout << "*arr = arr[0] = " << *arr1 << std::endl;
	std::cout << "*(arr1 + 4) = arr[4] = " << *(arr1 + 4) << std::endl;

	//����� �������� �������� �� ��������� ����� ��������� ��������� ����� ��������� ���������
	// ���_���������

}