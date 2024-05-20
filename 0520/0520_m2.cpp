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
	void intro() override
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
	void intro() override
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
	Teacher* teacher = new Teacher(names[0]);
	Student* student1 = new Student(names[1]);
	Student* student2 = new Student(names[2]);


	// pList에 할당하는 코드 추가
	pList[0] = teacher;
	pList[1] = student1;
	pList[2] = student2;

	// overriding : virtual 을 사용하지 않으면, 부모 메소드가 작동한다.
	// 이유? -> 동적 바인딩 : 런 타임에서 실제 주소값에 해당하는 인스턴스를 확인

	for (auto p : pList)
	{				// <동적바인딩> - 실행 중에 = 런 타임
		p->intro(); // 주소값을 찾아가서 teacher 인스턴스의 내용 확인 (선생입니다 실행)
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


