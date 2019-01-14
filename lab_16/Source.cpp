
#include <iostream>
//шаблон функции, кот возвращает различные типы значений в зависимости от типов входных параметров;
//типы значений а зависимсти от ТИПОВ входных параметров
/*
template <typename MyType>
MyType myFunc(MyType * arr, int size) {
	MyType res = arr[0];
	for (int iter = 0; iter < size; iter++) {
		if (res < arr[iter])
			res = arr[iter];
	}
	return res;
}
template <typename MyType>
MyType myFunc(MyType * arr, int size) {
	MyType res = arr[0];
	for (int iter = 0; iter < size; iter++) {
		if (res < arr[iter])
			res = arr[iter];
	}
	return res;
}

template<typename TT>
class myList {
public:
	TT element;
	myList * prev;
	myList * next;
	myList();
	myList(TT el);

	myList<TT> next_elem() {
		return next;
	}
	void print();
	void push_back(TT new_elem);
};


int main() {
	 int * arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
	char * arrCh;
	double * arrD;

	arrI = new int[sizeI];
	arrCh = new char[sizeCh];
	arrD = new double[sizeD];

	std::cout << "Input arrI";
	for (int it = 0; it < sizeI; it++) {
	std::cin >> arrI[it];
	}
	std::cout << "Input arrCh";
	for (int it = 0; it < sizeCh; it++) {
	std::cin >> arrCh[it];
	}
	std::cout << "Input arrD";
	for (int it = 0; it < sizeD; it++) {
	std::cin >> arrD[it];
	}
	std::cout << "Max element int = " << myFunc(arrI, sizeI);
	std::cout << "Max element char = " << myFunc(arrCh, sizeCh);
	std::cout << "Max element double = " << myFunc(arrD, sizeD);
	
	myList<int> li(5);//как это сделать в маин список
	li.push_back(4);
	//li.push_back(7); 
	li.print();

	getchar();
	return 0;
}

template<typename TT>
myList<TT>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TT>
myList<TT>::myList(TT el)
{
	prev = NULL;
	next = NULL;
	element = el;
}

template<typename TT>
void myList<TT>::print()
{
	myList<TT> *temp = new myList<TT>;
	*temp = *this;
	while (temp->prev != NULL) {
		*temp = *temp->prev;
	}
	while (temp->next != NULL) {
		std::cout « temp->element « "\t";
		*temp = *temp->next;
	}
	std::cout « temp->element « "\t";
}

template<typename TT>
void myList<TT>::push_back(TT new_elem)
{
	myList<TT> *tmp = new myList<TT>;//указатель на новый элемент
	myList<TT> *tmp1 = new myList<TT>;//указатель на текущий элемент
	this->next = tmp;//изменяем указатель на следующий элемент
	*tmp1 = *this;//копия указателя на this
	tmp->element = new_elem;
	(tmp->prev) = tmp1;
	tmp->next = NULL;
	this->element = tmp->element;
	this->prev = tmp->prev;
	this->next = NULL;
}


/*double myFunc(double * arr, int size) {
double res = arr[0];
for (int iter = 0; iter < size;iter++) {
if (res < arr[iter ])
res = arr[iter];
}
return res;
}

int myFunc(int * arr, int size) {
int res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter ])
res = arr[iter];
}
return res;
}

char myFunc(char * arr, int size) {
char res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter ])
res = arr[iter];
}
return res;
}

// мин и макс массива для инт, чар, дабл- функции
int main()
{
	int num;
    int max = 0;
	std::cout << "Enter integer value: ";
	std::cin >> num; // получение от пользователя размера массива

	int *p_darr = new int[num]; // Выделение памяти для массива
	for (int i = 0; i < num; i++)
	{
		// Заполнение массива и вывод значений его элементов
		p_darr[i] = i;
		std:: cout << "Value of " << i << " element is " << p_darr[i];
	}
	for (p_darr[i]; i < num; i++)
	{
		if (p_darr[i]>max)
		{
			max == p_darr[i];
		}
		else 

	}
	delete[] p_darr; // очистка памяти
	return 0;*/
	

