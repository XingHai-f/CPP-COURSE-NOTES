/*
虚函数和动态绑定
问题：是不是虚函数的调用一定是动态绑定？ 肯定不是
在类的构造函数当中，调用虚函数，也是静态绑定（构造函数中调用其它函数（虚），不会发生动态绑定）
*/

#include <iostream>
using namespace std;

class Base {
public:
	Base(int data = 0) :mb(data) { cout << "Base()" << endl; }
	~Base() { cout << "~Base()" << endl; }
	virtual void show() { cout << "Base::show()" << endl; }
protected:
	int mb;
};

class Derive:public Base {
public:
	Derive(int data = 0) :Base(data), md(data) { cout << "Derive()" << endl; }
	~Derive() { cout << "~Derive()" << endl; }
	void show() { cout << "Derive::show()" << endl; }
private:
	int md;
};

int main() {
	Base b;
	Derive d;

	// 静态绑定，用对象本身调用虚函数，是静态绑定
	b.show(); // 虚函数  call Base::show()
	d.show(); // 虚函数  call Base::show()

	// 动态绑定（必须由指针调用虚函数） 
	Base* pb1 = &b;
	pb1->show();
	Base* pb2 = &d;
	pb2->show();

	// 动态绑定（必须由引用变量调用虚函数） 
	Base& rb1 = b;
	rb1.show();
	Base& rb2 = d;
	rb2.show();
	

	// 动态绑定（虚函数通过指针或者引用变量调用，才发生动态绑定）
	Derive* pb1 = &d;
	pb1->show();
	Derive& rb1 = d;
	rb1.show();

	Derive* pb2 = (Derive*)&b;
	pb2->show(); // 动态绑定 pb2 -> b vfptr -> Base vftable Base::show() 

	return 0;
}
