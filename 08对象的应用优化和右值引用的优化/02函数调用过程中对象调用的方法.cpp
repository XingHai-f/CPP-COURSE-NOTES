#include <iostream>
using namespace std;

class Test
{
public:
	Test(int data = 10) :ma(data)
	{
		cout << "Test(int)" << endl;
	}
	~Test() { cout << "~Test()" << endl; }
	Test(const Test& t) :ma(t.ma)
	{
		cout << "Test(const Test& t) " << endl;
	}
	void operator=(const Test& t)
	{
		cout << "operator=" << endl;
		ma = t.ma;
	}
	int getData()const { return ma; }
private:
	int ma;
};

Test GetObject(Test t) // 不能返回局部的或者临时对象的指针或者引用
{
	int val = t.getData();
	Test tmp(val);
	return tmp;
}

int main()
{
	Test t1;
	Test t2;
	t2 = GetObject(t1);
	
	return 0;
}

/*
Test(int)
Test(int)
Test(const Test& t)
Test(int)
Test(const Test& t)
~Test()
~Test()
operator=
~Test()
~Test()
~Test()
*/