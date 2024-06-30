#include <iostream>
#include <memory>
using namespace std;

// 智能指针 保证能做到资源的自动释放
// 利用栈上的对象出作用域自动析构的特征，来做到资源的自动释放的
// CSmartPtr<int> *p = new CSmartPtr<int>(new int); delete p;裸指针
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T *ptr=nullptr
		:mptr(ptr)){}
	~CSmartPtr() 
	{ 
		delete mptr;
		mptr = nullptr;
	}

	T& operator*() { return *mptr; }
	T& operator->() { return mptr; }
private:
	T* mptr;
};
int main() 
{
	/*
	CSmartPtr<int> ptr1(new int);

	// data堆 heap堆 stack堆
	int* p = new int(10);
	*p = 10;
	delete p;
	*/

	/* 
	不带引用计数的智能指针
	auto_ptr:C++库里面
	C++11新标准:
	scoped_ptr
	scoped_ptr(const scoped_ptr<T>&) = delete;
	scoped_ptr<T>& operator=(const scoped_ptr<T>&) = delete;

	推荐使用：
	unique_ptr
	unique_ptr(const unique_ptr<T>&) = delete;
	unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;



	怎么解决浅拷贝的问题！！！

	//CSmartPtr<int> p1(new int);
	//CSmartPtr<int> p2(p1);

	auto_ptr<int> ptr1(new int);
	auto_ptr<int> ptr2(ptr1);

	*ptr2 = 20;
	cout << *ptr1 << endl;

	不推荐使用auto_ptr,vector<auto_ptr<int>> vec1;vec2(vec1);

	std::move => C++11 右值引用 std::move得到当前变量的右值类型
	*/

	unique_ptr<int> p1(new int);
	unique_ptr<int> p2(std::move(p1));

	return 0;
}