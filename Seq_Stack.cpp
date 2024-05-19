#include <iostream>
#include <cstdlib> // 为了使用 rand() 函数
using namespace std;

class SeqStack {
public:
    void init(int size = 10) {
        _pstack = new int[size];
        _top = -1; // 栈顶指针初始化为 -1，表示栈为空
        _size = size;
    }
    
    void push(int val) { // 入栈函数，用于将值'val'压入栈中
        if (full())
            resize(); // 如果栈满，则调用'resize()'方法扩展栈的大小
        _pstack[++_top] = val; // 将值'val'放入栈顶，并将'_top'增加 1
    }

    void pop() { // 出栈函数，用于将栈顶元素弹出
        if (empty()) // 栈为空，则返回
            return;
        --_top; // 栈顶指针减 1，表示弹出栈顶元素
    }
    
    void release() { // 用于释放动态分配的数组
        delete[] _pstack;
        _pstack = nullptr; // 将指针设置为'nullptr'，防止悬空指针
    }

    int top() { // 访问栈顶元素的函数，返回栈顶元素的值
        if (empty()) { // 栈为空，则抛出异常
            throw std::out_of_range("Stack is empty");
        }
        return _pstack[_top];
    } 

    bool empty() { return _top == -1; } // 返回栈是否为空的布尔值
    bool full() { return _top == _size - 1; } // 返回栈是否已满的布尔值

private:
    int* _pstack; // 开辟动态数组，存储顺序栈的元素
    int _top;     // 指向栈顶元素的位置
    int _size;    // 数组扩容的总大小

    void resize() { // 用于扩展栈的容量
        int* ptmp = new int[_size * 2];
        for (int i = 0; i < _size; ++i) { // 将旧数组的元素复制到新数组中
            ptmp[i] = _pstack[i];
        }
        delete[] _pstack;  // 释放旧数组的内存
        _pstack = ptmp;   // 将'_pstack'指向新数组
        _size *= 2;       
    }
};

int main() {
    SeqStack s;
    s.init(5);

    for (int i = 0; i < 15; ++i) { // 使用'for'循环将 15 个随机数压入栈中，数值范围为 0 到 99
        s.push(rand() % 100);
    }
    while (!s.empty()) { // 使用'while'循环弹出并打印栈中的所有元素，直到栈为空
        cout << s.top() << " ";
        s.pop();
    }
    s.release();
    return 0;
}
