#include <iostream>
using namespace std;

struct Animal {
	virtual void speak() {
		cout << "Animal::speak()" << endl;
	}
	virtual void run() {
		cout << "Animal::run()" << endl;
	}

	Animal() {
		cout << "Animal::Animal()" << endl;
	}

	virtual ~Animal() {
		cout << "Animal::~Animal()" << endl;
	}
};

struct Cat : Animal {
	void speak() {
		cout << "Cat::speak()" << endl;
	}
	void run() {
		cout << "Cat::run()" << endl;
	}

	Cat() {
		cout << "Cat::Cat()" << endl;
	}

	~Cat() {
		cout << "Cat::~Cat()" << endl;
	}
};

/* 
 //调用speak
 Animal *cat = new Cat();
 cat->speak();

 // ebp-8是指针变量cat的地址

 // eax是Cat对象的地址
 mov         eax,dword ptr [ebp-8]

 // 取出Cat对象最前面的4个字节给edx（Cat对象最前面的4个字节为虚表的地址值）
 // 取出虚表的地址值给edx
 mov         edx,dword ptr [eax]

 // 取出虚表的最前面4个字节给eax
 // 取出Cat::speak的函数调用地址给eax
 mov         eax,dword ptr [edx]
 
 // call Cat::speak
 call        eax
*/

/*
 //调用run
 Animal *cat = new Cat();
 cat->run();

 // ebp-8是指针变量cat的地址

 // eax是Cat对象的地址
 mov         eax,dword ptr [ebp-8]

 // 取出Cat对象最前面的4个字节给edx（Cat对象最前面的4个字节为虚表的地址值）
 // 取出虚表的地址值给edx
 mov         edx,dword ptr [eax]

 // 跳过虚表的最前面4个字节，取出4个字节赋值给eax
 // 取出Cat::run的函数调用地址给eax
 mov         eax,dword ptr [edx+4]

 // call Cat::run
 call        eax
*/

int main() {
	// 动态性

	Animal* cat0 = new Cat();
	cat0->speak();
	cat0->run();
	delete cat0;

	/*Animal *cat0 = new WhiteCat();
	cat0->speak();
	cat0->run();

	WhiteCat *cat1 = new WhiteWhiteCat();
	cat1->speak();
	cat1->run();*/

	/*Animal *anim = new Animal();
	anim->speak();
	anim->run();

	Animal *cat = new Cat();
	cat->speak();
	cat->run();*/

	getchar();
	return 0;
}



//struct WhiteCat : Cat {
//	void speak() {
//		cout << "WhiteCat::speak()" << endl;
//	}
//	void run() {
//		cout << "WhiteCat::run()" << endl;
//	}
//};
//
//struct WhiteWhiteCat : WhiteCat {
//	void speak() {
//		cout << "WhiteWhiteCat::speak()" << endl;
//	}
//	void run() {
//		cout << "WhiteWhiteCat::run()" << endl;
//	}
//};