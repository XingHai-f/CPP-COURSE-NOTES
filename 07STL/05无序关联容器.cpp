/*
无序关联容器 => 链式哈希表 增删查O(1)
set:集合 key  map：映射表 [key,value]
unordered_set 单重集合
unordered_multiset 多重集合
unordered_map 单重映射表
unordered_multimap 多重映射表
*/


#include <iostream>
// 使用有序关联容器包含的头文件
#include <set> // set multiset
#include <map> // map multimap
// 使用无序关联容器包含的头文件
#include <unordered_set>
#include <unordered_map>

#include <string>
using namespace std;
/*
关联容器：
1.各个容器底层的数据结构  O(1)  O(log2n)
2.常用增删查方法
增加：insert(val)
遍历：iterator自己搜索，调用find成员方法
删除：erase(key) erase(it)
*/

int main()
{
	// 处理海量数据查重复；去重复的时候

	/*
	map中存的都是一个一个的pair对象
	[key,value]
	struct pair
	{
		first; => key
		second; => value
	}

	map的operator[]
	1.查询
	2.如果key不存在，它会插入一对数据[key,string()]
	V& operator[](const K &key)
	{
		insert({key,V()});
	}
	*/
	unordered_map<int, string> map1;
	// 可选的插入方式
	map1.insert(make_pair(1000, "张三"));
	map1.insert({ 1010,"李四" }); // map表增加元素
	map1.insert({ 1020,"王五" });
	map1.insert({ 1030,"王凯" });

	auto it1 = map1.find(1030);
	if (it1 != map1.end())
	{
		// it1 -> pair对象
		cout << "key:" << it1->first << " value:" << it1->second << endl;
	}

	/*
	map1.erase(1020); // {1020,"王五"}删除了
	// map1[2000]; key:2000 vaule:""
	map1[2000] = "刘硕"; //相当于map1.insert({2000,"刘硕"})；
	map1[1000] = "张三2";
	cout << map1.size() << endl;
	// map operator[](key) => value  查询
	cout << map1[1000] << endl;
	*/
#if 0
	unordered_set<int> set1; // 不会存储key值重复的元素
	// unordered_multiset<int> set1; 多重集合允许重复的元素
	for (int i = 0; i < 50; ++i)
	{
		set1.insert(rand() % 20 + 1); // 由哈希表的函数决定插入函数位置
		// vector/deque/list(线性表要指向位置，需要迭代器)  insert(it(迭代器),val(值)) 
	}

	// cout << set1.size() << endl;
	// cout << set1.count(15) << endl;

	auto it1 = set1.begin();
	for (; it1 != set1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	set1.erase(20); // 按key值删除元素
	for (it1 = set1.begin(); it1 != set1.end(); )
	{
		if (*it1 == 30)
		{
			it1 = set1.erase(it1); // 调用erase，it1迭代器就失效了
		}
		else
		{
			++it1;
		}
	}
	it1 = set1.find(20);
	if (it1 != set1.end())
	{
		set1.erase(it1);
	}

	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;
#endif

	return 0;
}