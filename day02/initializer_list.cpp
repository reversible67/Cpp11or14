#include <iostream>
#include <initializer_list>  // 注意这个头文件
/*
initializer_list是C++11中的一个特性 它允许你使用{}中的值来初始化容器或数组
通常用于初始化标准库容器，比如std::vector、std::set、std::map以及数组
std::vector<int> arr = {1, 2, 3, 4, 5};
std::set<int> myset = {1, 2, 3, 4, 5, 2};
std::map<int, char> mymap = {{1, a}, {2, b}, {3, c}};

或者这种方式
std::vector<int> arr {1, 2, 3, 4, 5};
std::set<int> myset {1, 2, 3, 4, 5, 2};
std::map<int, char> mymap {{1, a}, {2, b}, {3, c}};
这种初始化方式使代码更简洁和可读，在背后使用了initializer_list的机制
*/

int main()
{
    // 直接使用初始化列表  缺点就是不能够动态添加元素  但是非常方便
    // std::initializer_list 相比于 std::vector 更为轻量级 它只存储了一个
    // 指向列表内存的指针和一个表示元素数量的整型变量 而std::vector还需要
    // 维护其插入、迭代、删除等等操作所需要的其他辅助资源
    std::initializer_list<int> numbers = {1, 2, 3, 4, 5};
    for(const int &num : numbers)
    {
        std::cout << num << " ";
    }
    return 0;
}
/*
注意一下，如果不显示提供initializer_list作为形参的构造函数，是不能用初始化列表来初始化实例对象的。
比如，你以为可以，但实际上不可以的这种情况：
class MyClass 
{
public:
	// 构造函数使用 std::vector 作为参数
	MyClass(const std::vector<int>& values) 
		: numbers(values) {}

private:
	std::vector<int> numbers;
};

int main() 
{
	MyClass obj1 = { 1, 2, 3, 4, 5 };
	return 0;
}
但可以这样：MyClass obj1({1,2,3,4,5});

以上都针对容器而言，不包含容器的自定义类是可以直接用初始化列表的
#include <vector>
class MyClass
{
public:
	MyClass(const int& a, const int& b)
		: m_A(a), m_B(b) {}
private:
	int m_A;
	int m_B;
};

int main()
{
	MyClass obj1 = {1, 2};
	return 0;
}
*/