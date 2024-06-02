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