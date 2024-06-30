#include <iostream>
#include <memory>
using namespace std;

// 对资源进行引用计数的类
template<typename T>
class RefCnt
{
public:
	RefCnt(T* ptr = nullptr)
		:mptr(ptr)
	{
		if (mptr != nullptr)
			mcount = 1;
	}
	void addRef() { mcount++; } // 增加资源的引用计数
	int delRef() { return --mcount; }
private:
	T* mptr;
	int mcount;
};

template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T* ptr = nullptr)
		:mptr(ptr) 
	{
		mpRefCnt = new RefCnt<T>(mptr);
	}
	~CSmartPtr()
	{
		if (0 == mpRefCnt->delRef())
		{
			delete mptr;
			mptr = nullptr;
		}
	}

	T& operator*() { return *mptr; }
	T* operator->() { return mptr; }

	CSmartPtr(const CSmartPtr<T>& src)
		:mptr(src.mptr),mpRefCnt(src.mpRefCnt)
	{
		if (mptr != nullptr)
			mpRefCnt->addRef();
	}
	CSmartPtr<T>& operator=(const CSmartPtr<T>& src)
	{
		if (this == &src)
			return *this;
		if (0 == mpRefCnt->delRef())
			delete mptr;
		mptr = src.mptr;
		mpRefCnt = src.mpRefCnt;
		mpRefCnt->addRef();
		return *this;
	}
private:
	T* mptr; // 指向该资源的指针
	RefCnt<T>* mpRefCnt; // 指向该资源引用计数对象的指针
};
int main()
{
	/*
	带引用计数的智能指针shared_ptr和weak_ptr
	带引用计数：多个智能指针可以管理同一个资源
	带引用计数：给每一个对象资源，匹配一个引用计数；
	智能指针 =》使用资源的时候 =》引用计数+1
	智能指针 =》不使用资源的时候 =》引用计数-1 =》!=0 0资源释放了
	*/
	CSmartPtr<int> ptr1(new int);
	CSmartPtr<int> ptr2(ptr1);

	CSmartPtr<int> ptr3;
	ptr3 = ptr2;
	*ptr1 = 20;
	cout << *ptr2 << " " << *ptr3 << endl;
	return 0;
}