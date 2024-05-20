/*
C++移动构造函数(移动语义的具体实现)
所谓移动语义，指的就是以移动而非深拷贝的方式初始化含有指针成员的类对象

以前面的demo类为例，该类的对象都包含一个整形的指针成员，其默认指向的是容纳一个整形变量的堆空间。
当使用 get_demo() 函数返回的临时对象初始化 a 时，我们只需要将临时对象的 num 指针直接浅拷贝给 a.num，
然后修改该临时对象中 num 指针的指向（通常另其指向 NULL），这样就完成了 a.num 的初始化。
*/

/*
事实上，对于程序执行过程中产生的临时对象，往往只用于传递数据（没有其它的用处），
并且会很快会被销毁。因此在使用临时对象初始化新对象时，
我们可以将其包含的指针成员指向的内存资源直接移给新对象所有，无需再新拷贝一份，这大大提高了初始化的执行效率。
*/

#include<iostream>

class demo{
public:
    demo()
    : num(new int(0)){
        std::cout << "construct!" << std::endl;
    }

    // 深拷贝构造函数
    demo(const demo& d)
    : num(new int(*d.num)){
        std::cout << "copy construct!" << std::endl;
    }

    // 添加移动构造函数
    demo(demo &&d)
    : num(d.num){
        d.num = nullptr;
        std::cout << "move construct!" << std::endl;
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
g++ MoveConstruct.cpp -std=c++0x -fno-elide-constructors -std=c++11
编译器未优化的执行结果如下：
construct!
move construct!
class destruct!
move construct!
class destruct!
class destruct!
*/
/*
通过执行结果我们不难得知，当为 demo 类添加移动构造函数之后，使用临时对象初始化 a 对象过程中产生的 2 次拷贝操作，都转由移动构造函数完成

当类中同时包含拷贝构造函数和移动构造函数时，如果使用临时对象初始化当前类的对象，
编译器会优先调用移动构造函数来完成此操作。只有当类中没有合适的移动构造函数时，编译器才会退而求其次，调用拷贝构造函数。

在实际开发中，通常在类中自定义移动构造函数的同时，会再为其自定义一个适当的拷贝构造函数，由此当用户利用右值初始化类对象时，会调用移动构造函数；
使用左值（非右值）初始化类对象时，会调用拷贝构造函数。
*/