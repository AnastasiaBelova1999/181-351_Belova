#include <iostream>

struct node //п одно звено нашего будущего дерева
{
	int info;
	node *l, *r; //Левая и Правая часть дерева
};

node *tree = NULL;

/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(int a, node **t)
{
	if ((*t) == NULL)
	{
		(*t) = new node; //Выделяем память
		(*t)->info = a; //Кладем в выделенное место аргумент a
		(*t)->l = (*t)->r = NULL; //Очищаем память для следующего роста
		return;
	}
	//Дерево есть
	if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
	else push(a, &(*t)->l); //Иначе кладем его влево
}

void print(node *t, int u)
{
	if (t == NULL) return; //Если дерево пустое, то отображать нечего, выходим
	else
	{
		print(t->l, ++u); //С помощью рекурсивного посещаем левое поддерево
		for (int i = 0; i < u; ++i) std::cout << "|";
		std::cout << t->info << std::endl; //И показываем элемент
		u--;
	}
	print(t->r, ++u); //С помощью рекурсии посещаем правое поддерево
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n; //Количество элементов
	int s; //Число, передаваемое в дерево
	std::cout << "введите количество элементов  ";
	std::cin >> n; //Вводим количество элементов

	for (int i = 0; i < n; ++i)
	{
		std::cout << "ведите число  ";
		std::cin >> s;

		push(s, &tree); //И кладем в дерево
	}
	std::cout << "ваше дерево\n";
	print(tree, 0);
	std::cin.ignore().get();
}