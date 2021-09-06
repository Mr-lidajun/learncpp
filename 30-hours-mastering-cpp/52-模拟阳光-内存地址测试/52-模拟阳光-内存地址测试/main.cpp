#include <iostream>
using namespace std;

struct Sun {
	int temp1;
	int temp2;
	int value; // 阳光值
};

// 游戏数据
struct GameData {
	int temp;
	Sun* sun;
};

// 游戏全局数据
GameData* g_data;

int main() {

	g_data = new GameData();
	g_data->sun = new Sun();
	g_data->sun->value = 20;

	while (1) {
		cout << g_data->sun->value << endl;
	}

	//0x057A3D0 // 全局变量g_data的地址值
	//[0x057A3D0] // GameData对象的地址值
	//[0x057A3D0 + 0x4] // sun对象的地址值
	//[[0x057A3D0 + 0x4] + 0x8] // value阳光值的内存地址 

	/*
	局部变量a的地址是ebp-8
	全局变量g_age的地址是0x057A3D0
	*/

	getchar();
	return 0;
}