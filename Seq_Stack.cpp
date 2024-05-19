#include <iostream>
#include <cstdlib> // 为了使用 rand() 函数
using namespace std;

class SeqStack {
public:
    void init(int size = 10) {
        _pstack = new int[size];
        _top = -1;
        _size = size;
    }
    void release() {
        delete[] _pstack;
        _pstack = nullptr;
    }
    void push(int val) {
        if (full())
            resize();
        _pstack[++_top] = val;
    }
    void pop() {
        if (empty())
            return;
        --_top;
    }
    int top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _pstack[_top];
    }
    bool empty() { return _top == -1; }
    bool full() { return _top == _size - 1; }
private:
    int* _pstack; // 开辟动态数组，存储顺序栈的元素
    int _top;     // 指向栈顶元素的位置
    int _size;    // 数组扩容的总大小

    void resize() {
        int* ptmp = new int[_size * 2];
        for (int i = 0; i < _size; ++i) {
            ptmp[i] = _pstack[i];
        }
        delete[] _pstack;
        _pstack = ptmp;
        _size *= 2;
    }
};

int main() {
    SeqStack s;
    s.init(5);

    for (int i = 0; i < 15; ++i) {
        s.push(rand() % 100);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    s.release();
    return 0;
}
