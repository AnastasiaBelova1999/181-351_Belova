
//Lab_14

#include <iostream>
#include <string>
#include <stack> // ���������� ���������� ��� ������������� �����
#include <queue> //���������� ���������� ��� ������������� �������
#include <deque>//���������� ��� ������������� ����
// - �������� ������ � ������� �����
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
			S.push(exp[i]);//���������� �������� � ����
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();//�������� �������� �����
		}
	}
	return S.empty() ? true : false;//��������� ���� �� ����
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
	���� � ��� ��������� ������, ������� ��������
	�� �������� FILO(first in � last out; ������ ������ � ��������� ����).
	� ����� ��� ��������,�.�. ������ ���������� � ������������� ��������.
	������ ������� ����� ��������� �� ��������� �������.
	�������� ������� ��������� �� NULL.
	�����������: �������� �������� � ���������� �������� �������� �� const �����.
	*/

	/*std::stack<int> stackInt;//stack <��� ������> <���>; -�������� �����
	int i = 0, a = 0;
	std::cout << "������� 5 ����� �����: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a);  // ��������� ��������� �����
		i++;
	}
	if (stackInt.empty()) // ��������� ���� �� ���� (���)
		std::cout << "���� �� ����";
	std::cout << "������� ������� �����: " << stackInt.top() << std::endl;
	stackInt.pop();  // ������� ������� �������
	std::cout << "����� ������� �������: " << stackInt.top() << std::endl;
	*/

	//� ������� ����� �������� ��������
	//� ����� ����� ������� � ��������� ����� ��������
	//C��������� �������� �� ������� ����� �������


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


	/*	������� � ��� ��������� ������, ������� ��������� �� ��������
		LILO(last in � last out : ��������� ������ � ��������� �����).
		*/

		/*std::queue <int> MyQueue;  // ������� �������
		std::cout << "������� 7 �����: " << std::endl;
		for (i = 0; i < 7; i++) {
			std::cin >> a;
			MyQueue.push(a);  // ��������� � ������� ��������
		}
		std::cout << std::endl;
		std::cout << "������ ������� � �������: " << MyQueue.front() << std::endl;
		MyQueue.pop();  // ������� ������� �� �������
		std::cout << "������ ������� (����� ��������): " << MyQueue.front() << std::endl;
		if (!MyQueue.empty()) // ��������� ����� �� ������� (���)
			std::cout << "������� �� �����!";
		*/
		/*
		������� � �����������(priority_queue) � ��� ������� �������,
		�� � ��� ����� ������� ����������� � ����� �����,
		����� ������� ���� ������������� �� ��������.
		*/
		/*
		std::priority_queue <int> priority_q;  // ��������� ������������ �������
		std::cout << "������� 7 �����: " << std::endl;
		for (i = 0; i < 7; i++) {
			std::cin >> a;
			priority_q.push(a);  // ��������� �������� � �������
			//std::copy(priority_q.pop(),priority_q.top(), std::ostream_iterator(std::cout, " "));
		}
		// ������� ������
		std::cout << "������ ������� �������: " << priority_q.top();
		*/
		//�������� ���������� ����� ���
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
	���(����.deque � ������������ �� double - ended queue, ������������� �������)
	���������� ��������� ������, � ������� ����� ������� � ��������� ��������
	��� � ������, ��� � � �����.
	��� �������� � ������ ��� ��, ��� � �������.*/

//List-��� ��������� ������, ������� ��������� �� ���������� �������.
//��� ������, ��� ����� ������� ����� ������ � ���������� � � ��������� ���������.
//� ����������� ������ ��� ��������.
//�����:
//���������� � �������� ����� �������������� ������.
//����� ���������� � �������� � �����, �� ����� ����� �������� � ������� ������� � ������ ����������.
//������ :
//��������� ��������� � ���������, ����������� � ������.
//insert
//� ������� ��� ����� �������� ����� ������� � ����� ����� ����������(� ����� ������ ��� ������).��� ��� �� �������� :
//insert(<�������>, <��������>);
//������ ���������� �������� � ��������������.��� ����������� ����������, ��� ��� ������� ��� �����.
//������ �������� ����� ������.����� ����� ���� ��� ���������� ��� � ������ ��������(5 ��������).
//string cpp = "��� �����";
///insert(it, cpp);


//set � ��� ���������, ������� ������������� ��������� ����������� �������� � ������� �����������. �� ��� ���������� ���������� ��������, set ����� ������� ������ ���� ��� ���������. �� ������� ��� ��� �������� ����������.
//�������� set < [���] > <���>;
//set <int> st; ������
//����� �������� ����� ������� ����� ������������ ������� insert()
//st.insert(<��������>);
//������� ��������� 
//set < [���] > :: iterator it;
//����� �������� ������� �� ������������ set [���] ������ ��������� � ����� ����������.
/*
copy
copy([������], [�����], ostream_iterator<[���] >(cout, [������]));
[������] � �������� ����������� �� ������ �������, ������� �� ����� �������.��� �� ����� ������ �������� �� ������� ��� �������� ��������.
[�����] � �������� ����������� �� ������, �� ������� ����� ������������� �����.
[���] � ��� ������ ��������� ���������(��� ����������).
<������> � ����� ����� �������, ��� �������� ����� ����������.������ ��������� ������(cout, " ").
erase
� ������ ��� �����:
������� �����-�� ���������� ������� � <���>.erase([��������])
���� ������� ������������ �������� ��������
<���>.erase([������], [�����]);
[������] � � ������ �������� ����� ����������� �������� (������������).
[�����] � �� ������ �������� ����� ������������ (�� ������������).
*/
