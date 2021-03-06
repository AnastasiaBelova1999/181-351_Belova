// lab2.cpp: определяет точку входа для консольного приложения.
//
#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a = 300;
	int b = 560;


	cout << "a*a*b*b=" << a * a * b * b << endl;
	cout << "b/a=" << 1. * b / a << endl;// % остаток от деления
	cout << "symbol_A+a=" << 'A' + a << endl;

	cout << "type\t\t";
	cout << "size\t\t";
	cout << "min\t\t\t";
	cout << "max";

	cout << " \n bool\t\t" << sizeof(bool) << "\t\t" << 0 << "\t\t\t" << 1 << endl;
	cout << " char\t\t" << sizeof(char) << "\t\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;
	cout << " int\t\t" << sizeof(int) << "\t\t" << INT_MIN << "\t\t" << INT_MAX << endl;
	cout << " short\t\t" << sizeof(short) << "\t\t" << SHRT_MIN << "\t\t\t" << SHRT_MAX << endl;
	cout << " long\t\t" << sizeof(int) << "\t\t" << LONG_MIN << "\t\t" << LONG_MAX << endl;
	cout << " long long\t" << sizeof(long long) << "\t\t" << LLONG_MIN << "\t" << LLONG_MAX << endl;

	return 0;
}
/*git init
4)Добавляем в наш репозиторий необходимые файлы
 (>git add *.cpp *h *.sln *.vcxproj *.filters)
git config user.name Имя на гитхабе
git config user.email ...
5) создаем новую версию (>git commit -am “181-351_Belova%DATE%”) 
6) Производим диагностику (>git status; >git log)
Работа с глобальным рипозиторием (удаленный)
1. Создаем аккаунт на удаленном сервисе (github.com)
2. Создаем пустой проэкт. Имя латинскими буквами(без пробелов). Копируем его адресс.
3. Связываем локальный рипозиторий и удаленный
>git remote add my labs https://gitlab.com/username/proj_name.git
4. Отправляем
>git push имя репы на гитхабе master
На чужом компе открываем проэкт впервые:
>git clone https://url.git 
> git pull
*/