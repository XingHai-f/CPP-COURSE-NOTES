#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;


#if 0
/*
函数对象 => C语言里面的函数指针
把有operator()小括号运算符重载函数的对象，称作函数对象或者仿函数
*/
/*
// 使用C的函数指针解决方案
template<typename T>
bool mygreater(T a, T b)
{
	return a > b;
}
template<typename T>
bool myless(T a, T b)
{
	return a < b;
}
*/

/*
1.通过函数对象调用operator()，可以省略函数的调用开销，比通过函数指针
调用函数（不能够inline内联调用）效率高
2.因为函数对象是用类生成的，所以可以添加相关的成员变量，用来记录函数对象
使用时更多的信息
*/
//C++函数对象的版本实现
template<typename T>
class mygreater
{
public:
	bool operator()(T a, T b) // 二元函数对象
	{
		return a > b;
	}
};
template<typename T>
class myless
{
public:
	bool operator()(T a, T b)  // 二元函数对象
	{
		return a < b;
	}
};

// compare是C++的库函数模板
template<typename T,typename Compare>
bool compare(T a, T b,Compare comp)
{
	// 通过函数指针调用函数，是没有办法内联的，效率很低，因为有函数调用开销
	return comp(a, b);	// operator(a,b)
}

int main()
{
	cout << compare(10, 20, mygreater<int>) << endl;
	cout << compare(10, 20, myless<int>) << endl;


	return 0;
}
#endif


int main()
{
	// 举例1
	priority_queue<int> que1; // vector
	for (int i = 0; i < 10; ++i)
	{
		que1.push(rand() % 100);
	}
	while (!que1.empty())
	{
		cout << que1.top() << " ";
		que1.pop();
	}
	cout << endl;

	using MinHeap = priority_queue<int,vector<int>, greater<int>>;
	MinHeap que2; // vector
	for (int i = 0; i < 10; ++i)
	{
		que2.push(rand() % 100);
	}
	while (!que2.empty())
	{
		cout << que2.top() << " ";
		que2.pop();
	}
	cout << endl;

	// 举例2
	set<int, greater<int>> set1;
	for (int i = 0; i < 10; ++i)
	{
		set1.insert(rand() % 100);
	}
	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

