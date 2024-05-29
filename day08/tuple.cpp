/*
C++11 标准新引入了一种类模板，命名为 tuple（中文可直译为元组）。tuple 最大的特点是：实例化的对象可以存储任意数量、任意类型的数据。

tuple 的应用场景很广泛，例如当需要存储多个不同类型的元素时，可以使用 tuple；当函数需要返回多个数据时，可以将这些数据存储在 tuple 中，函数只需返回一个 tuple 对象即可。
*/
#include <iostream>
#include <tuple>

int main(){
    std::tuple<int, float, std::string> t1(41, 6.3, "nico");
    std::cout << "tuple<int, float, std::string>, sizeof = " << sizeof(t1) << std::endl;
    std::cout << "t1: " << std::get<0>(t1) << ' ' << std::get<1>(t1) << ' ' << std::get<2>(t1) << std::endl;    // 获取下标 0 1 2处的元素

    // 利用auto关键字  自动获取类型     make_tuple() 函数，它以模板的形式定义在 头文件中，功能是创建一个 tuple 右值对象（或者临时对象）
    auto t2 = std::make_tuple(22, 44, "hello");
    std::cout << "t2 sizeof = " << sizeof(t2) << std::endl;
    std::cout << "t2: " << std::get<0>(t2) << ' ' << std::get<1>(t2) << ' ' << std::get<2>(t2) << std::endl;

    // 比大小操作
    if(t1 < t2){
        std::cout << "t1 < t2" << std::endl;
    }
    else if(t1 > t2){
        std::cout << "t1 > t2" << std::endl;
    }
    else{
        std::cout << "t1 = t2" << std::endl;
    }

    // tie绑定操作进行复制
    std::tuple<int, float, std::string> t3(77, 1.1, "more light");
    int i1;
    float f1;
    std::string s1;
    tie(i1, f1, s1) = t3;
    std::cout << "i1 = " << i1 << " f1 = " << f1 << " s1 = " << s1 << std::endl;

    // tuple_size函数   功能是获取某个 tuple 对象中元素的个数
    typedef std::tuple<int, float, std::string> TupleType;              // 对tuple<int, float, std::string>取别名 为 TupleType
    int value = std::tuple_size<TupleType>::value;
    std::cout << "TupleType对象的元素个数为: " << value << std::endl;    // 3

    // tuple_element<i, type>::type函数 它只有一个成员变量 type，功能是获取某个 tuple 对象第 i+1 个元素的类型
    std::tuple_element<0, TupleType>::type i2 = 1;
    std::cout << "i2 = " << i2 << std::endl;                           // i2 = 1

    return 0;
}