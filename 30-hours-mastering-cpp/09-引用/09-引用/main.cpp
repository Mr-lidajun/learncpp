#include <iostream>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

/*
* 在C语言中，使用指针（Pointer）可以间接获取、修改某个变量的值
* 在C++中，使用引用（Reference）可以起到跟指针类似的功能
* 引用相当于是变量的别名（基本数据类型、枚举、结构体、类、指针、数组等，都可以有引用）
* 注意点
* 引用相当于是变量的别名（基本数据类型、枚举、结构体、类、指针、数组等，都可以有引用）
* 对引用做计算，就是对引用所指向的变量做计算
* 在定义的时候就必须初始化，一旦指向了某个变量，就不可以再改变，“从一而终”
* 可以利用引用初始化另一个引用，相当于某个变量的多个别名
* 不存在【引用的引用、指向引用的指针、引用数组】 
* 
* 引用存在的价值之一：比指针更安全、函数返回值可以被赋值
*/
void test() {
	// 结构体的引用
	Date d = { 2021, 8, 17 };

	Date& refDate = d;
	refDate.day = 2014;

	int age = 10;
	// 指针p
	int* p = &age;
	// 指针的引用
	int*& ref = p;
	*p = 30;
	int height = 30;
	// 修改ref引用的指向
	ref = &height;

	// 指针数组，数组里面可以存放3个int*
	int* arr[3] = { p , p, p };

	// 用于指向数组的指针
	int arr1[3] = { 1,2,3 };
	int(*arr2)[3] = &arr1;
	*arr[0] = 6;

	cout << *arr[0] << endl;

	// 数组的引用
	int array[] = { 1,2,3 };
	int(&refArray)[3] = array;
	refArray[0] = 10;
}

/* 
* 常引用（Const Reference）
* 引用可以被const修饰，这样就无法通过引用修改数据了，可以称为常引用
* const必须写在&符号的左边，才能算是常引用
*
*/
void test2() {
	int age = 10;
	const int& ref = age;
	const int* p = &age;
	//ref = 30;
	//*p = 28;

	int height = 20;

	// 指针变量p1不能修改指向，可以利用指向变量p间接修改所指向的变量
	int* const p1 = &age;
	//p2 = &height;
	*p1 = 30;

	// 指向变量p2可以修改指向，不可以利用指向变量p2间接修改所指向的变量
	int const* p2 = &age;
	p2 = &height;
	//*p2 = 30;

	// const修饰的是指针变量ref1，仅仅是指针变量不能修改指向
	// ref1不能修改指向，但是可以通过ref1间接修改所指向的变量
	int& const ref1 = age;
	ref1 = 30;

	// ref2不能修改指向，不可以通过ref2间接修改所指向的变量
	int const& ref2 = age;
	//ref2 = 40;
	//*ref2 = &height;
}

int func() {
	return 8;
}

int sum(int &v1, int &v2) {
	cout << "sum(int &v1, int &v2)" << endl;
	return v1 + v2;
}

int sum(const int &v1, const int &v2) {
	cout << "sum(const int &v1, const int &v2)" << endl;
	return v1 + v2;
}

/*
* const引用的特点
* 可以指向临时数据（常量、表达式、函数返回值等）
* 可以指向不同类型的数据
* 作为函数参数时（此规则也适用于const指针）
* 可以接受const和非const实参（非const引用，只能接受非const实参）
* 可以跟非const引用构成重载
* 
*/
void test3() {
	int age = 10;
	const double& ref = age;

	int a = 1;
	int b = 2;
	const int& ref1 = 30;
	const int& ref2 = a + b;
	const int& ref3 = func();

	// 非const实参
	int c = 10;
	int d = 20;
	sum(c, d);

	// const实参
	const int e = 10;
	const int f = 20;
	sum(e, f);
	sum(10, 20);
}

// 不同编程语言转成的汇编是一样的么？
// Java、C++、OC、Swift写代码 --> 汇编\机器码（取决于CPU架构）
// X86 ARM

/* 
* 当常引用指向了不同类型的数据时，会产生临时变量，即引用指向的并不是初始化时的那个变量
*/
int main() {
	int age = 10;
	const int& rAge = age;
	age = 30;

	/*
	 mov         dword ptr [ebp-0Ch],0Ah
	 lea         eax,[ebp-0Ch]
	 mov         dword ptr [ebp-18h],eax
	 mov         dword ptr [ebp-0Ch],1Eh
	*/

	cout << "age is " << age << endl;
	cout << "rAge is " << rAge << endl;

	int age2 = 10;
	const long& rAge2 = age2;
	age2 = 30;

	/*
	 mov         dword ptr [ebp-0Ch],0Ah

	 mov         eax,dword ptr [ebp-0Ch]
	 mov         dword ptr [ebp-24h],eax
	 lea         ecx,[ebp-24h]
	 mov         dword ptr [ebp-18h],ecx

	 mov         dword ptr [ebp-0Ch],1Eh
	*/

	cout << "age is " << age2 << endl;
	cout << "rAge is " << rAge2 << endl;

	getchar();
	return 0;
}