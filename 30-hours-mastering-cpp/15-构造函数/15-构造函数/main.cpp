#include <iostream>
using namespace std;

struct Person {
	int m_age;
	int m_money;

	Person() {
		m_age = 0;
		cout << "Person()" << endl;
	}

	Person(int age) {
		m_age = age;
		cout << "Person(int age)" << endl;
	}

	Person(int age, int money) {
		m_age = age;
		m_money = money;
		cout << "Person(int age, int money)" << endl;
	}

	void display() {
		cout << "age is " << m_age << ", money is " << m_money << endl;
	}
};

struct Person2 {
	int m_age;

	Person2() {
		cout << "Person2::Person2()" << endl;
	}

	void run() {
		cout << "Person2::run() - " << m_age << endl;
	}
};

void test() {
	// 会调用构造函数
	Person person1;
	person1.display();

	Person person2(20);
	person2.display();

	Person person3(10, 20);
	person3.display();

	// 在堆空间创建对象
	// 会调用构造函数
	Person2* p = new Person2;
	delete p;

	// 通过malloc分配的对象不会调用构造函数
	Person2* p1 = (Person2*)malloc(sizeof(Person2));
	p1->m_age = 10;
	p1->run();

	free(p1);
}

Person g_person0; // Person()
Person g_person1(); // 函数申明
Person g_person2(10); // Person(int)

int main() {
	Person person0;  // Person();
	Person person1(); // 函数申明
	Person person2(20); // Person(int)
	
	Person* p0 = new Person; // Person();
	Person* p1 = new Person(); // Person();
	Person* p2 = new Person(30); // Person(int)

	/* 4个无参，3个有参，一共创建了7个Person对象 */

	getchar();
	return 0;
}