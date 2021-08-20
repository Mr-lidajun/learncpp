#include <iostream>
using namespace std;
#include "Person.h"

//class Person {
//	int m_height;
//};

namespace MJ {
	int g_age;

	void func() {
		cout << "MJ::func()" << endl;
	}

	//class Person {
	//	int m_age;
	//	int m_money;
	//};
}

namespace FX {
	int g_age;
}

void func() {
	cout << "func()" << endl;
}

int main() {
	using namespace MJ;
	MJ::func();
	::func();
	::MJ::func();

	//Person person;
	MJ::Person person;

	cout << sizeof(person) << endl;

	getchar();
	return 0;
}