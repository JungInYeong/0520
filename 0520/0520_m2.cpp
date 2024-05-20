#include <iostream>
using namespace std;

class Person
{
public:
	virtual void intro()
	{
		cout << "사람입니다~" << endl;
	}
};

class Student : public Person
{
	string name;

public:
	Student(string name)
	{
		this->name = name;
	}
	void intro()
	{
		cout << name << "학생입니다" << endl;
	}
	void learn()
	{
		cout << "배웁니다." << endl;
	}
};

class Teacher : public Person
{
	string name;

public:
	Teacher(string name)
	{
		this->name = name;
	}
	void intro()
	{
		cout << name << "선생입니다" << endl;

	}
	void teach()
	{
		cout << "가르칩니다" << endl;
	}

};

int main()
{
	Person* pList[3];
	string names[3];

	cout << "3명의 이름을 입력해 주세요(선생님, 학생, 학생) : " << endl;
	cin >> names[0] >> names[1] >> names[2];
	
	cout << endl;

	// names[] 배열 이용하여 각 class 생성 
	Teacher teacher = Teacher(names[0]);
	Student student1 = Student(names[1]);
	Student student2 = Student(names[2]);


	// pList에 할당하는 코드 추가
	pList[0] = &teacher;
	pList[1] = &student1;
	pList[2] = &student2;

	for (auto p : pList)
	{
		p->intro();
	}
	cout << endl;
	// 각 class의 고유 함수 실행 (teach(), learn(), learn())
	Teacher* t = (Teacher*)pList[0];
	t->teach();
	Student* s1 = (Student*)pList[1];
	s1->learn();
	Student* s2 = (Student*)pList[2];
	s2->learn();


	return 0;
}


