#include <iostream>
using namespace std;

// 方法 == 函数 
// 文件默认编码：GBK GB2312 GB18030

// Java: 先有类，再有方法（函数）

void test() {
	// VS很多设计比较反人类
	//cout << "Hello World!" << endl;

	//cout << "Hello";
	////cout << "\n";
	//cout << endl;
	//cout << "World";

	// 面向对象、运算符（操作符）重载
	//cout << "Hello" << endl << "World";

	cout << "please a number:" << endl;

	int age;
	cin >> age;

	cout << "age is " << age << endl;

	getchar();
	getchar();
}

int main() {
	cout << "Hello World!" << endl;

	// 等待键盘输入（如果敲回车，就会读取键盘输入）
	getchar();
	return 0;
}