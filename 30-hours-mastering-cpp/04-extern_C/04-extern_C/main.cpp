#include <iostream>
using namespace std;

/*
	第三方框架\库：可能是用C语言写的开源库
*/


//extern "C" {
//	//int sum(int v1, int v2);
//	//int delta(int v1, int v2);
//	//int divide(int v1, int v2);
//
//	#include "math.h"
//}

#include "other.h"
#include "math.h"

//extern "C" void other();

int main() {
	//func();
	
	// other();

	cout << sum(10, 20) << endl;
	cout << delta(30, 20) << endl;
	cout << divide(30, 3) << endl;

	getchar();
	return 0;
}

//extern "C" void func() {
//
//}
//
//extern "C" void func(int v) {
//
//}

//extern "C" {
//	void func() {
//
//	}
//
//	void func(int v) {
//
//	}
//}

//extern "C" void func();
//extern "C" void func(int v);

//void func();
//extern "C" void func(int v);

//void func() {
//
//}
//
//void func(int v) {
//
//}