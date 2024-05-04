#include<iostream>

int main()
{
    int id = 0;
    auto f = [&id](int param)
    {
        std::cout << "id = " << id << std::endl;
        ++id;
        ++param;
    };

    id = 42;
    f(7);
    f(7);
    f(7);
    std::cout << id << std::endl;

    return 0;
}
/*
注意这里是[&id]  所以对id做出改变 再调用匿名函数时  不同于值传递  此时对打印结果有改变的
*/