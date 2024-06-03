#include <iostream>
using namespace std;

class String {
public:
	// 构造函数
	String(const char* p = nullptr) {
		if (p != nullptr) {
			_pstr = new char[strlen(p) + 1];
			strcpy(_pstr, p);
		}
		else {
			_pstr = new char[1];
			*_pstr = '\0';
		}
	}
	// 析构函数
	~String() {
		delete[]_pstr;
		_pstr = nullptr;
	}
	// 拷贝构造函数
	String(const String& str) {
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
	}
	// 赋值运算符重载
	String& operator=(const String& str) {
		if (this == &str)
			return *this;
		delete[]_pstr;

		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
		return *this;
	}
	// 大于运算符重载
	bool operator>(const String& str)const {
		return strcmp(_pstr, str._pstr) > 0;
	}
	// 小于运算符重载
	bool operator<(const String& str)const {
		return strcmp(_pstr, str._pstr) < 0;
	}
	// 等于运算符重载
	bool operator==(const String& str)const {
		return strcmp(_pstr, str._pstr) == 0;
	}
	// 返回字符串长度
	int lengh()const { return strlen(_pstr); }
	// 返回C字符串
	const char* c_str()const { return _pstr; }

	// 下标运算符重载
	//char ch = str6[6]; str6[6] = '7'
	char& operator[](int index) { return _pstr[index]; }
	//char ch = str6[6]; 不允许修改！str6[6] = '7'
	const char& operator[](int index)const { return _pstr[index]; }

	//给String字符串类型提供迭代器的实现
	class iterator 
	{
	public:
		iterator(char* p = nullptr) :_p(p){}
		bool operator!=(const iterator& it) {
			return _p != it._p;
		}
		void operator++()
		{
			++_p;
		}
		char& operator*() { return *_p; }
	private:
		char* _p;
	};
	//begin返回的是容器底层首元素的迭代器的表示
	iterator begin() { return iterator(_pstr); }
	//end返回的是容器末层元素后继位置的迭代器的表示
	iterator end() { return iterator(_pstr + lengh()); }

private:
	char* _pstr;

	friend String operator+(const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream& out, const String& str);
};
// 加法运算符重载
String operator+(const String& lhs, const String& rhs) {
	char* ptmp = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	strcpy(ptmp, lhs._pstr);
	strcat(ptmp, rhs._pstr);
	String result(ptmp);
	delete[] ptmp; // 释放临时分配的内存
	return String(ptmp);
}
// 输出流运算符重载
ostream& operator<<(ostream& out, const String& str) {
	out << str._pstr;
	return out;
}

int main() {
	//迭代器的功能：提供一种统一的方式，来透明的遍历容器
	String str1 = "hello world!";
	//迭代器的类型
	String::iterator it = str1.begin();
	for (; it != str1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//以C++11 foreach的方式来遍历容器的内部元素的值=>底层，还是通过迭代器进行遍历的
	for (char ch : str1) {
		cout << ch << " ";
	}
	cout << endl;
}
