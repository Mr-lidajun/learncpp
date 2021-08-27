#include <iostream>
using namespace std;

class Car {
	int m_price;
	char* m_name;
public:
	Car(int price = 0, const char* name = NULL) : m_price(price) {
		if (name == NULL) return;

		// 申请新的堆空间
		m_name = new char[strlen(name) + 1] {};
		// 拷贝字符串数据到新的堆空间
		strcpy(m_name, name);
	}

	~Car() {
		if (m_name == NULL) return;
		delete[] m_name;
		m_name = NULL;
	}

	void display() {
		cout << "price is " << m_price << ", name is " << m_name << endl;
	}
};

Car* g_car;

void test() {
	char name2[] = { 'b', 'm', 'w', '\0' };
	cout << name2 << endl;
	cout << strlen(name2) << endl;

	g_car = new Car(100, name2);
}

int main() {
	//const char* name = "bmw";

	//char name[] = { 'b', 'm', 'w', '\0' };

	//char* name = new char[4]{ 'b', 'm', 'w', '\0' };
	
	//test();
	//char name3[] = { 'a', 'b', 'c', '\0' };
	Car* car = new Car(200, "bmw");
	g_car->display();

	//delete[] name;
	
	
	

	getchar();
	return 0;
}