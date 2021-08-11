#include <iostream>
using namespace std;

int age = 6;

//int sum(int v1 = 5, int v2 = age);

//void test(int a) {
//	cout << "test(int) - " << a << endl;
//}
//
//void func(int v1, void(*p)(int) = test) {
//	p(v1);
//}

int sum(int v1 = 3, int v2 = 4) {
	return v1 + v2;
}

int main() {
	
	sum(1, 4);
	sum(2, 4);
	sum(3, 4);

	//func(30);
	//func(20, test);

	//void(*p)(int) = test;
	//p(10);

	//cout << sum() << endl; // 11
	//cout << sum(10) << endl; // 16
	//cout << sum(10, 20) << endl; // 30


	getchar();
	return 0;
}

//int sum(int v1, int v2) {
//	return v1 + v2;
//}