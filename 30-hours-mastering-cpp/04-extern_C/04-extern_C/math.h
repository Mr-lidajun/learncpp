// header file: 存放函数的声明

// 如果没有定义过ABC这个宏，那么就定义ABC
#ifndef __MATH_H
#define __MATH_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int sum(int v1, int v2);
	int delta(int v1, int v2);
	int divide(int v1, int v2);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !__MATH_H