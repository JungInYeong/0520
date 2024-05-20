// 실습1
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
		cout << "맛, 가격, 이름, 제조사를 입력하세요 : ";
		cin >> this->m_taste >> this->m_price >> this->m_name >> this->m_company;
	}
	void printCompany() override { cout << "캔디 제조사 : " << m_company << endl; }
};

class Chocolate : public Snack
{
public:
	string m_shape;

	Chocolate()
	{
		cout << "모양, 가격, 이름, 제조사를 입력하세요 : ";
		cin >> this->m_shape >> this->m_price >> this->m_name >> this->m_company;
	}
	void printCompany() override { cout << "초콜릿 제조사 : " << m_company << endl; }
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
	cout << endl;
	Candy* can2 = (Candy*)snackbasket[1];
	can2->printCompany();
	cout << endl;
	Chocolate* choco1 = (Chocolate*)snackbasket[2];
	choco1->printCompany();
	cout << endl;
	Chocolate* choco2 = (Chocolate*)snackbasket[3];
	choco2->printCompany();
	cout << endl;
	return 0;
}

/*
heap
-> 프로그램이 실행되는 중에 사용되는 메모리
-> 100% 사용자가 고나리 (new, delete)
-> 조금 더 느림

stack
->프로그램 실행 전 할당 메모리
->new 키워드 외 모든것
->조금 더 빠름, 운영체제 별로 메모리 용량 한계
*/