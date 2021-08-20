#include <iostream>
using namespace std;

struct Person {
	int m_age;
	char* m_name;

	//Person() {
	//	
	//}

	Person() {
		memset(this, 0, sizeof(Person));
	}

};

// 全局区（成员变量初始化为0）
Person g_person;

int main() {
	// 栈空间（成员变量不会被初始化）
	//Person p1;

	Person* p2 = new Person; // 成员变量不会被初始化
	Person* p3 = new Person(); // 成员变量初始化为0
	Person* p4 = new Person[3]; // 成员变量不会被初始化
	Person* p5 = new Person[3](); // 3个Person对象的成员变量都初始化为0
	Person* p6 = new Person[3]{}; // 3个Person对象的成员变量都初始化为0

	cout << g_person.m_age << endl;
	//cout << p1.m_age << endl;
	cout << p2->m_age << endl;
	cout << p3->m_age << endl;
	cout << p4[0].m_age << endl;
	cout << p5[0].m_age << endl;
	cout << p6[0].m_age << endl;

	getchar();
	return 0;
}