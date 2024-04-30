#include<iostream>

/*
noexcept是C++11新引入的关键字，noexcept既是说明符，也是运算符。
作为说明符，它的作用是指定函数是否抛出异常；作为运算符，它的作用是编译时检查，如果表达式不会抛出任何异常则返回 true，否则返回false。
noexcept主要作用：减少运行时开销
语法格式： noexcept 等价于 noexcept(true)
noexcept(false)表示允许抛出异常  noexcept(true)表示不允许抛出异常
如果在运行时，noexecpt函数向外抛出了异常（如果函数内部捕捉了异常并完成处理，这种情况不算抛出异常），程序会直接终止，
调用std::terminate()函数，该函数内部会调用std::abort()终止程序。
*/

// noexcept可以用于函数声明和函数定义中，如果将函数标记为noexcept，那么编译器就可以进行一些优化，从而提高程序性能。
void func1() noexcept 
{
    // Function body
    std::cout << "该函数不会抛出任何异常，编译器会进行优化" << std::endl;
}

void func2() noexcept(false)
{
    // Function body
    std::cout << "如果该函数可能抛出异常，则用noexcept(false)" << std::endl;
}

void myFunc() noexcept
{
    std::cout << "myFunc() called" << std::endl;
}

int main()
{
    try{
        myFunc();
    }
    catch(...){
        std::cout << "exception caught" << std::endl;
    }

    return 0;
}

/*
我们并没有在主函数中捕获任何异常，这是因为我们的noexcept函数不会抛出异常
总之，noexcept关键字是一个非常有用的语法糖，它可以帮助我们指示函数是否可能抛出异常，从而进行一些优化。
如果您需要编写高性能的C++程序，noexcept关键字是您应该考虑的一个重要工具。
*/