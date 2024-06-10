#include <iostream>
using namespace std;

/*
C++提供的四种类型转换方式
int a =(double) b;
const_cast：去掉（指针或者引用）常量属性的一个类型转换
staic_cast:：提供编译器认为安全的类型转换（没有任何联系的类型之间的转换就被否定）
reinterpret_cast：类似C风格的强制类型转换
dynamic_cast：主要用在继承结构中，可以支持RTTI类型识别上下转换
*/

class Base {
public:
	virtual void func() = 0;
};
class Derive1 :public Base {
public:
	void func() { cout << "call Derive1::func()" << endl; }
};
class Derive2 :public Base {
public:
	void func() { cout << "call Derive2::func()" << endl; }
	// Derive2实现新功能的API接口函数
	void derive02func() { 
		cout << "call Derive2::derive02func()" << endl; 
	}

};
/*
typeid(*p).name() == "Derive"
*/
void showfunc(Base* p) {
	/*
	dynamic_cast会检查p指针是否指向一个Derive2类型的对象？
	p->vfptr->vftable RTTI信息，如果是，dynamic_cast转换类型成功，
	返回Derive2对象的地址，给pd2；否则返回nullptr。
	*/
	Derive2* pd2 = dynamic_cast<Derive2*>(p);
	if (pd2 != nullptr) {
		pd2->derive02func();
	}
	else {
		p->func(); // 动态绑定 *p的类型 Derive2 derive02func
	}
}

int main() {

	Derive1 d1;
	Derive2 d2;
	showfunc(&d1);
	showfunc(&d2);

	//const int a = 10;
	//double* p1 = (double*)&a;
	//int* p2 = const_cast<int*>(&a);  C++转换要与a变量类型一致
	//const_cast<这里面必须是指针、引用类型或者指向对象类型成员的指针 int* int&>
	//int b = const_cast<int(错)>(a);
	
	//static_cast  基类 《=》 派生类  转换可以用static_cast
	int a = 10;
	char b = static_cast<int>(a);
	
	/*
	不可转换
	int* p = nullptr;
	short* p = static_cast<short*>(p);
	*/

	return 0;
}