#include<iostream>

int main()
{
    int id = 0;
    auto f = [id]() mutable {
        std::cout << "id = " << id << std::endl;
        ++id;
    };

    id = 42;
    f();
    f();
    f();
    std::cout << id << std::endl;

    return 0;
}
/*
[id]表示 取外部的变量id 
()表示lambda函数没有参数
有mutable
{...} 表示函数体里面的动作

这个函数相当于是一个类
class Functor
{
private:
    int id;
public:
    void operator()(){
        std::cout << "id = " << id << std::endl;
        ++id;
    }
};

Functor f;
f();
这个类中重载了() 所以对象就可以像函数一样调用
为什么打印结果是 0 1 2 42 
把这个匿名函数当作Functor类一样去理解  它有一个传入[id] 等价于值传递  且 id = 0 相当于有一个属于自己'对象'的id 
对这个id进行++; 所以分别是 0 1 2
*/