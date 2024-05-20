// �ǽ�1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Snack
{
public:
	int m_price;
	string m_name;
	string m_company;
	Snack() {};
	virtual void printCompany() = 0;
};

class Candy : public Snack
{
public:
	string m_taste;

	Candy()
	{
		cout << "��, ����, �̸�, �����縦 �Է��ϼ��� : ";
		cin >> this->m_taste >> this->m_price >> this->m_name >> this->m_company;
	}
	void printCompany() override { cout << "ĵ�� ������ : " << m_company << endl; }
};

class Chocolate : public Snack
{
public:
	string m_shape;

	Chocolate()
	{
		cout << "���, ����, �̸�, �����縦 �Է��ϼ��� : ";
		cin >> this->m_shape >> this->m_price >> this->m_name >> this->m_company;
	}
	void printCompany() override { cout << "���ݸ� ������ : " << m_company << endl; }
};

int main()
{
	Snack* candy1 = new Candy();
	Snack* candy2 = new Candy();
	Snack* chocolate1 = new Chocolate();
	Snack* chocolate2 = new Chocolate();

	Snack* snackbasket[4] = { candy1, candy2, chocolate1, chocolate2 };
	/*for (auto s : snackbasket)
	{
		s->printCompany();
		
	}*/
	cout << endl;
	Candy* can1 = (Candy*)snackbasket[0];
	can1->printCompany();
	Candy* can2 = (Candy*)snackbasket[1];
	can2->printCompany();
	Chocolate* choco1 = (Chocolate*)snackbasket[2];
	choco1->printCompany();
	Chocolate* choco2 = (Chocolate*)snackbasket[3];
	choco2->printCompany();	
	return 0;
}

/*
heap
-> ���α׷��� ����Ǵ� �߿� ���Ǵ� �޸�
-> 100% ����ڰ� ���� (new, delete)
-> ���� �� ����

stack
->���α׷� ���� �� �Ҵ� �޸�
->new Ű���� �� ����
->���� �� ����, �ü�� ���� �޸� �뷮 �Ѱ�
*/