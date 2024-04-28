#include <iostream>
#include <vector>

/*
在 C++11 之前的版本（C++98 和 C++ 03）中，定义变量或者声明变量之前都必须指明它的类型，比如 int、char 等；
但是在一些比较灵活的语言中，比如 C#、JavaScript、PHP、Python 等，程序员在定义变量时可以不指明具体的类型，
而是让编译器（或者解释器）自己去推导，这就让代码的编写更加方便。

C++11 为了顺应这种趋势也开始支持自动类型推导了！C++11 使用 auto 关键字来支持自动类型推导。

在之前的 C++ 版本中，auto 关键字用来指明变量的存储类型，它和 static 关键字是相对的。
auto 表示变量是自动存储的，这也是编译器的默认规则，所以写不写都一样，一般我们也不写，这使得 auto 关键字的存在变得非常鸡肋。

C++11 赋予 auto 关键字新的含义，使用它来做自动类型推导。也就是说，使用了 auto 关键字以后，
编译器会在编译期间自动推导出变量的类型，这样我们就不用手动指明变量的数据类型了
*/
double d(double i)
{
    double temp = i;
    return temp;   
}

int main()
{
    std::vector<int> v1;
    std::vector<std::vector<int>> v2;
    auto a = 42;             // a has type int  a的类型为int型
    auto b = double(6.66);   // b has type double b的类型为double型
    /*
    有了auto这个屠龙宝刀  并不是让我们无脑的一直用
    在type特别长(你实在懒得打那么多字)或者实在是很复杂(一时间想不出来，但是大约有印象)的时候，使用auto是特别有用的
    */
    std::vector<int>::iterator it1 = v1.begin();
    auto it2 = v1.begin();
    std::vector<std::vector<int>>::iterator it3 = v2.begin();
    auto it4 = v2.begin();
    
    return 0;
}