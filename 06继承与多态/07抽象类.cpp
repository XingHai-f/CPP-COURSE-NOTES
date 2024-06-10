/*
抽象类和普通类有什么区别？
一般把什么类设计成抽象类？ 基类
*/

#include <iostream>
#include <string>
using namespace std;

// 动物基类   泛指   类->抽象一个实体的类型
/*
定义Animal的初衷，并不是让Animal抽象某个实体的类型
1.string _name; 让所有的动物实体类通过继承Animal直接复用该属性
2.给所有的派生类保留统一的覆盖/重写接口

拥有纯虚函数的类，叫做抽象类！（Animal）
Animal A； NO!
抽象类不能再实例化对象了，但是可以定义指针和引用变量
*/
class Animal {
public:
    Animal(string name) :_name(name) {}
    // 纯虚函数
    virtual void bark() = 0;
protected:
    string _name;
};

// 动物实体类
class Cat :public Animal {
public:
    Cat(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:miao miao!" << endl; }
};

class Dog :public Animal {
public:
    Dog(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:wang wang!" << endl; }
};

class Pig :public Animal {
public:
    Pig(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:heng heng!" << endl; }
};

void bark(Animal* p) {
    p->bark(); // Animal::bark虚函数，动态绑定了
    /*
    p->cat Cat vftable  &Cat::bark()
    p->dog Dog vftable  &Dog::bark()
    p->pig Pig vftable  &Pig::bark()
    */
}

//汽车的基类
class Car {

};


int main() {
    Cat cat("猫咪");
    Dog dog("二哈");
    Pig pig("佩奇");

    bark(&cat);
    bark(&dog);
    bark(&pig);

    return 0;
}