#include<iostream>

/*
override关键字 
如果派生类在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，否则代码将无法通过编译
*/

class Base
{
public:
    virtual void print() = 0;
    virtual void dijkstra() = 0;
    virtual void myfunc() = 0;
};

class Derived : public Base
{
public:
    virtual void print() override;    // 编译器会告诉你缺少该函数的定义
    // void djikstra() override; // 无法通过编译 拼写错误 并非重载
    virtual void dijkstra() override;
    virtual void myfunc() override;   // 没有问题 对myfunc进行了重载
};

void Derived::myfunc()
{
    std::cout << "hello" << std::endl;
}

void Derived::print()
{
    std::cout << "my print" << std::endl;
}

void Derived::dijkstra()
{
    std::cout << "dijkstra" << std::endl;
}

int main()
{
    Derived derived;
    derived.print();
    derived.dijkstra();
    derived.print();

    return 0;
}