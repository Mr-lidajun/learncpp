#include <iostream>
using namespace std;

//struct Person {
//private:
//	int m_age;
//
//public:
//	void setAge(int age) {
//		m_age = age;
//	}
//
//	int getAge() {
//		return m_age;
//	}
//};
//
//struct Student : public Person {
//
//};
//
//struct GoodStudent : public Student {
//	void work() {
//
//	}
//};

//class Person {
//private:
//	int m_age;
//public:
//	void run() {
//
//	}
//};
//
//struct Student : public Person {
//
//};
//
//class GoodStudent : public Student {
//
//};

struct Person {
	int m_age;
};

int main() {
	/*Person person;
	person.m_age = 10;*/

	// GoodStudent gs;

	/*GoodStudent gs;
	gs.run();*/

	// 8个字节
	int a = 10;
	int b = 11;
	int c = 12;

	Person* pp = new Person[3];
	cout << pp->m_age << endl;
	cout << pp[0].m_age << endl;
	cout << pp[1].m_age << endl;
	cout << (*(pp + 1)).m_age << endl;

	/*
	Visual C++
	*/

	getchar();
	return 0;
}