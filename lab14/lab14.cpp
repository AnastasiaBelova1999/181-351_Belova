
//Lab_14

#include <iostream>
#include <string>
#include <stack> // подключаем библиотеку для использования стека
#include <queue> //подключили библиотеку для использования очереди
#include <deque>//библиотека для использования дека
// - проверка скобок с помощью стека
bool ArePair(char open, char clos)
{
	if (open == '(' && clos == ')') return true;
	else if (open == '{' && clos == '}') return true;
	else if (open == '[' && clos == ']') return true;
	return false;
}
bool AreParanthesesBalanced(std::string exp)
{
	std::stack<char>  S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);//добавление элемента в стэк
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();//удаление элемента стека
		}
	}
	return S.empty() ? true : false;//проверяем пуст ли стэк
}

int main()
{
	setlocale(LC_ALL, "rus");

	/*Code to test the function AreParanthesesBalanced*/
	std::string expression;
	std::cout << "Enter an expression:  ";
	std::cin >> expression;
	if (AreParanthesesBalanced(expression))
		std::cout << "Balanced\n";
	else
		std::cout << "Not Balanced\n";

	/*
	СТЕК — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).
	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.
	Достоинство: операции удаления и добавления элемента делаются за const время.
	*/

	/*std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a);  // добавляем введенное число
		i++;
	}
	if (stackInt.empty()) // проверяем пуст ли стек (нет)
		std::cout << "Стек не пуст";
	std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
	stackInt.pop();  // удаляем верхний элемент
	std::cout << "Новый верхний элемент: " << stackInt.top() << std::endl;
	*/

	//В ВЕКТОРЕ ЛЕГКО НАХОДИТЬ ЭЛЕМЕНТЫ
	//В ЛИСТЕ ЛЕГКО УДАЛЯТЬ И ВСТАВЛЯТЬ НОВЫЕ ЭЛЕМЕНТЫ
	//Cортировка учеников по классам через очередь


	std::queue<std::string> Class_9;
	std::queue<std::string> Class_10;
	std::queue<std::string> Class_11;

	int input_class;
	std::cin >> input_class;

	while (input_class != 0)
	{

		if (input_class == 9)
		{
			std::string student;
			std::cin >> student;
			Class_9.push(student);
		}

		if (input_class == 10)
		{
			std::string student;
			std::cin >> student;
			Class_10.push(student);
		}

		if (input_class == 11)
		{
			std::string student;
			std::cin >> student;
			Class_11.push(student);
		}

		std::cin >> input_class;

	}

	while (!Class_9.empty())
	{
		std::cout << Class_9.front() << std::endl;
		Class_9.pop();
	}

	while (!Class_10.empty())
	{
		std::cout << Class_10.front() << std::endl;
		Class_10.pop();
	}

	while (!Class_11.empty())
	{
		std::cout << Class_11.front() << std::endl;
		Class_11.pop();
	}


	/*	ОЧЕРЕДЬ — это структура данных, которая построена по принципу
		LILO(last in — last out : последним пришел — последним вышел).
		*/

		/*std::queue <int> MyQueue;  // создали очередь
		std::cout << "Введите 7 чисел: " << std::endl;
		for (i = 0; i < 7; i++) {
			std::cin >> a;
			MyQueue.push(a);  // добавляем в очередь элементы
		}
		std::cout << std::endl;
		std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
		MyQueue.pop();  // удаляем элемент из очереди
		std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;
		if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
			std::cout << "Очередь не пуста!";
		*/
		/*
		Очередь с приоритетом(priority_queue) — это обычная очередь,
		но в ней новый элемент добавляется в такое место,
		чтобы очередь была отсортирована по убыванию.
		*/
		/*
		std::priority_queue <int> priority_q;  // объявляем приоритетную очередь
		std::cout << "Введите 7 чисел: " << std::endl;
		for (i = 0; i < 7; i++) {
			std::cin >> a;
			priority_q.push(a);  // добавляем элементы в очередь
			//std::copy(priority_q.pop(),priority_q.top(), std::ostream_iterator(std::cout, " "));
		}
		// выводим первый
		std::cout << "Первый элемент очереди: " << priority_q.top();
		*/
		//проверка палиндрома через дек
	std::deque<std::string>p1;
	std::string input;
	std::cin >> input;
	p1.push_back(input);
	while (p1.size() > 1 && p1.front() == p1.back())
	{
		if (p1.front() == p1.back())
		{
			p1.pop_front();
			if (!p1.empty())
				p1.pop_back();
		}
		else
			std::cout << "no" << std::endl;
	}
	if (p1.size() == 1)
	{
		p1.pop_back();
		std::cout << "yes" << std::endl;
	}
	else
		std::cout << "no" << std::endl;
	return 0;
}
	/*
	ДЕК(англ.deque – аббревиатура от double - ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно удалять и добавлять элементы
	как в начало, так и в конец.
	Дек хранится в памяти так же, как и очередь.*/

//List-Это структура данных, которая построена на двусвязных списках.
//Это значит, что любой элемент знает только о предыдущем и о следующем элементах.
//У двусвязного списка нет индексов.
//Плюсы:
//Добавление и удаление ячеек осуществляется быстро.
//Кроме добавления и удаления в конец, мы также можем добавить и удалить элемент в начале контейнера.
//Минусы :
//Медленное обращение к элементам, находящимся в центре.
//insert
//С помощью его можно добавить новый элемент в любую часть контейнера(в нашем случае для списка).Вот как он работает :
//insert(<позиция>, <значение>);
//Первым аргументом передаем — местоположение.Оно указывается итератором, что это читайте вот здесь.
//Вторым значение новой ячейки.Здесь может быть как переменная так и просто значение(5 например).
//string cpp = "Это легко";
///insert(it, cpp);


//set — это контейнер, который автоматически сортирует добавляемые элементы в порядке возрастания. Но при добавлении одинаковых значений, set будет хранить только один его экземпляр. По другому его еще называют множеством.
//создание set < [тип] > <имя>;
//set <int> st; пример
//Чтобы добавить новый элемент нужно использовать функцию insert()
//st.insert(<значение>);
//содание итератора 
//set < [тип] > :: iterator it;
//Чтобы итератор работал на определенный set [тип] должен совпадать с типом контейнера.
/*
copy
copy([начала], [конец], ostream_iterator<[тип] >(cout, [отступ]));
[начала] — итератор указывающий на первый элемент, который мы хотим вывести.Так мы можем начать выводить со второго или третьего элемента.
[конец] — итератор указывающий на ячейку, до которой будет производиться вывод.
[тип] — тип данных выводимых элементов(тип контейнера).
<отступ> — здесь можно указать, что выводить между элементами.Обычно указывают пробел(cout, " ").
erase
С помощь нее можно:
Удалить какой-то конкретный элемент — <имя>.erase([итератор])
Либо удалить определенный диапазон значений
<имя>.erase([начала], [конец]);
[начала] — с какого элемента будет происходить удаление (включительно).
[конец] — до какого элемента будет продолжаться (не включительно).
*/
