// lab4.cpp : Указатели
//
#include <iostream>

/* Указатель - переменная, хранящая адрес(смещение) каких-либо данных
переменных в оперативной памяти(pointer)
ptr_a, ptr_b.
1. Указатель объявляется, как обычная переменная с добавлением звездочки
тип_данных * имя_указателя int * ptr_a
ptr_a = &a унарный оператор & амперсенд - оператор получения адреса
Фактически указатель это unsigned int или insigned long long,
так как отрицательных адресов нет.
2. Размер указателя
все указатели всегда одной и той же разрядности (размера)
каким бы ни был огромным тип данных (строка, объект, массив)
указатель на него всегда будет занимать 4/8 байт, что и является основным
преимуществом указателей.
3. Содержимое указателя
имя_указателя
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

	//Содержимое указателей

	std::cout << "ptr_int = " << ptr_int << std::endl;
	std::cout << "ptr_double = " << ptr_double << std::endl;
	std::cout << std::endl << "ptr_int = 0x" << std::hex << ptr_int << std::endl;

	std::cout << "arr = " << arr1 << std::endl;
	std::cout << "*arr = arr[0] = " << *arr1 << std::endl;
	std::cout << "*(arr1 + 4) = arr[4] = " << *(arr1 + 4) << std::endl;

	//Чтобы получить значение из указателя нужно поставить звездочку перед названием указателя
	// имя_указателя

}