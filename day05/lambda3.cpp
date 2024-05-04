#include<iostream>

int main()
{
    int id = 0;
    auto f = [id](){
        std::cout << "id = " << id << std::endl;
        //++id;  //因为是值传递 所以不能对外部参数做改变 没有加 mutable 时故编译器会报错
    };

    id = 42;
    f();
    f();
    f();
    std::cout << id << std::endl;

    return 0;
}