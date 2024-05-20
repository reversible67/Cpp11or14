/*
C++11 标准中借助右值引用可以为指定类添加移动构造函数，这样当使用该类的右值对象（可以理解为临时对象）初始化同类对象时，编译器会优先选择移动构造函数。

移动构造函数的调用时机是：用同类的右值对象初始化新对象。那么，用当前类的左值对象（有名称，能获取其存储地址的实例对象）初始化同类对象时，是否就无法调用移动构造函数了呢？
当然不是，C++11 标准中已经给出了解决方案，即调用 move() 函数。

move本意未“移动” 但是该函数并不能移动任何数据，它的功能很简单，就是将某个左值强制转为右值
基于move函数的特殊功能，其常用于实现移动语义
move()函数的用法很简单，语法格式为 move(arg)
其中arg表示指定的左值对象，该函数会返回arg对象的右值形式
*/
#include<iostream>

class movedemo{
public:
    movedemo()
    : num(new int(0)){
        std::cout << "construct!" << std::endl;
    }

    // 拷贝构造函数
    movedemo(const movedemo& d)
    : num(new int(*d.num)){
        std::cout << "copy construct!" << std::endl;
    }

    // 移动构造函数
    movedemo(movedemo &&d)
    : num(d.num){
        d.num = nullptr;
        std::cout << "move construct!" << std::endl;
    }
private:
    int *num;
};

int main(){
    movedemo demo;

    movedemo demo2 = demo;

    movedemo demo3 = std::move(demo);

    return 0;
}
/*
运行结果：
construct!
copy construct!
move construct!

demo为左值  但是调用了一次拷贝构造函数 一次移动构造函数
*/