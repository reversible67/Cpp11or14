/*
在 C++ 11 标准之前（C++ 98/03 标准中），如果想用其它对象初始化一个同类的新对象，只能借助类中的复制（拷贝）构造函数。
拷贝构造函数的实现原理很简单，就是为新对象复制一份和其它对象一模一样的数据。
需要注意的是，当类中拥有指针类型的成员变量时，拷贝构造函数中需要以深拷贝(而非浅拷贝)的方式复制该指针成员
*/
#include <iostream>

class demo{
public:
    demo() 
    : num(new int(0)){
        std::cout << "construct!" << std::endl;
    }

    // 拷贝构造函数
    demo(const demo& d)
    : num(new int(*d.num)){
        std::cout << "copy construct!" << std::endl;
    }

    ~demo(){
        delete num;
        std::cout << "class destruct!" << std::endl;
    }
private:
    int *num;
};

demo get_demo(){
    return demo();
}

int main(){
    demo a = get_demo();
    return 0;
}
/*
main函数执行过程：
可以看到，程序中定义了一个可返回 demo 对象的 get_demo() 函数，用于在 main() 主函数中初始化 a 对象，其整个初始化的流程包含以下几个阶段：

1.执行 get_demo() 函数内部的 demo() 语句，即调用 demo 类的默认构造函数生成一个匿名对象；
2.执行 return demo() 语句，会调用拷贝构造函数复制一份之前生成的匿名对象，并将其作为 get_demo() 函数的返回值（函数体执行完毕之前，匿名对象会被析构销毁）；
3.执行 a = get_demo() 语句，再调用一次拷贝构造函数，将之前拷贝得到的临时对象复制给 a（此行代码执行完毕，get_demo() 函数返回的对象会被析构）；
4.程序执行结束前，会自行调用 demo 类的析构函数销毁 a。
*/
/*
输出结果:
编译器优化：
construct!
class destruct!

编译器未优化：
如果在 Linux 上使用g++ demo.cpp -fno-elide-constructors -std=c++11命令运行（其中 demo.cpp 是程序文件的名称），就可以看到完整的输出结果：
construct!
copy construct!
class destruct!
copy construct!
class destruct!
class destruct!
*/