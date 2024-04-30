#include<iostream>

/*
C++11 final 关键字
允许将类标记为final 在类后面使用关键字final 意味着继承该类会导致编译错误
即表示该类不能再被继承
C++中还允许将方法(虚函数)标记为fianal，这意味着无法在子类中重写该方法
*/

class Base final
{
public:
    void print();
    virtual void myfunc() final;
};

// 编译器会报错 不能将final类 类型用作基类
/*
class Derived : public Base
{

};
*/

int main()
{
    
    return 0;
}