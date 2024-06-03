/*
new和delete
1.malloc和new的区别？
a.malloc按字节开辟内存的；new开辟内存时需要指定类型 new int[10]
	所以malloc开辟内存返回的都是void*    operator new -> int*
b.malloc只负责开辟空间，new不仅仅有malloc的功能，可以进行数据的初始化
	new int(20);     new int[20]();      int()
c.malloc开辟内存失败返回nullptr指针；new抛出的是bad_alloc类型的异常

2.free和delete的区别？
delete (int*) p:调用析构函数；再free(p)


new和delete能混用吗？C++为什么区分单个元素和数组的内存分配和释放呢？
new delete
new[] delete[]
对于普通的编译器内置类型 new/delete[]   new[]/delete

自定义的类类型，有析构函数，为了调用正确的析构函数，那么开辟对象数组的时候，
会多开辟4个字节，记录对象的个数
*/

// 先调用operator new开辟内存空间，然后调用对象的构造函数（初始化）
void* operator new(size_t size)
{
	void* p = malloc(size);
	if (p == nullptr)
		throw bad_alloc();
	return p;
}

// delete p; 调用p指向对象的析构函数，再调用operator delete施放内存空间
void operator delete(void* ptr)
{
	free(ptr);
}