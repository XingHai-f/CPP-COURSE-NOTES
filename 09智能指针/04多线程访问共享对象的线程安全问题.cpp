#include <iostream>
#include <memory>
#include <thread>
using namespace std;

/*
C++开源网络库muduo库
多线程访问共享对象的线程安全问题
*/

class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	void testA() { cout << "非常好用的方法！" << endl; }
};
// 子线程
void handler01(weak_ptr<A> pw)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	 // q访问A对象的时候，需要侦测以下A对象是否存活
	shared_ptr<A> sp = pw.lock();
	if (sp != nullptr)
	{
		sp->testA();
	}
	else
	{
		cout << "A对象已经析构，不能再访问！" << endl;
	}
}
// main线程
int main()
{
	{
		shared_ptr<A> p(new A());
		thread t1(handler01, weak_ptr<A>(p));
		t1.detach();
	}
	std::this_thread::sleep_for(std::chrono::seconds(20));

	return 0;
}