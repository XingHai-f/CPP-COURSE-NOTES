#include <iostream>
using namespace std;
#if 0
int main() {
	// 右值引用
	int a = 10;
	int& b = a; // 左值：有内存、有名字  右值（常量、数字、临时量）：没名字（临时量）、没内存
	// int &&c = a; // 无法将左值绑定到右值引用
	/*
	int tmp = 20;
	const int &c = tmp;
	*/
	const int& c = 20; // 不能用左值引用绑定一个右值
	/*
	int tmp = 20;
	 int &&d = tmp;
	*/
	int&& d = 20; // 可以把一个右值绑定到一个右值引用上
	// CMyString&& e = CMyString("aaa");

	int& f = d; // 一个右值引用变量，本身是一个左值
	return 0;
}
#endif