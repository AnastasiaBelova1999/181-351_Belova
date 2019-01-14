#include <iostream>

struct node //� ���� ����� ������ �������� ������
{
	int info;
	node *l, *r; //����� � ������ ����� ������
};

node *tree = NULL;

/*������� ������ �������� � �������� ������*/
void push(int a, node **t)
{
	if ((*t) == NULL)
	{
		(*t) = new node; //�������� ������
		(*t)->info = a; //������ � ���������� ����� �������� a
		(*t)->l = (*t)->r = NULL; //������� ������ ��� ���������� �����
		return;
	}
	//������ ����
	if (a > (*t)->info) push(a, &(*t)->r); //���� �������� � ������ ��� ������� �������, ������ ��� ������
	else push(a, &(*t)->l); //����� ������ ��� �����
}

void print(node *t, int u)
{
	if (t == NULL) return; //���� ������ ������, �� ���������� ������, �������
	else
	{
		print(t->l, ++u); //� ������� ������������ �������� ����� ���������
		for (int i = 0; i < u; ++i) std::cout << "|";
		std::cout << t->info << std::endl; //� ���������� �������
		u--;
	}
	print(t->r, ++u); //� ������� �������� �������� ������ ���������
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n; //���������� ���������
	int s; //�����, ������������ � ������
	std::cout << "������� ���������� ���������  ";
	std::cin >> n; //������ ���������� ���������

	for (int i = 0; i < n; ++i)
	{
		std::cout << "������ �����  ";
		std::cin >> s;

		push(s, &tree); //� ������ � ������
	}
	std::cout << "���� ������\n";
	print(tree, 0);
	std::cin.ignore().get();
}