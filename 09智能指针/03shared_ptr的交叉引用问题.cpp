#include <iostream>
#include <memory>
using namespace std;

/*
shared_ptr:强智能指针 可以改变资源的引用计数
weak_ptr:弱智能指针 不会改变资源的引用计数
operator* operator->
weak_ptr =>(观察) shared_ptr =>(观察) 资源(内存)

强智能指针循环引用（交叉引用）是什么问题？什么结果？怎么解决？
造成new出来的资源无法释放！！！资源泄露问题
定义对象的时候，用强智能指针；引用对象的地方，使用弱智能指针
*/
class B;
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	weak_ptr<B> _ptrb;
private:
};
class B
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
	weak_ptr<A> _ptra;
};

int main()
{
	shared_ptr<A> pa(new A());
	shared_ptr<B> pb(new B());

	pa->_ptrb = pb;
	pb->_ptra = pa;

	cout << pa.use_count() << endl;
	cout << pb.use_count() << endl;

	return 0;
}


