#include<iostream>

/*
所谓匿名函数，简单地理解就是没有名称的函数，又常被称为 lambda 函数或者 lambda 表达式。
继 Python、Java、C#、PHP 等众多高级编程语言都支持 lambda 匿名函数后，
C++11 标准终于引入了 lambda，本节将带领大家系统地学习 lambda 表达式的具体用法。

定义lambda函数的语法格式如下：
[外部变量访问方式说明符] (参数) mutable -> 返回值类型
{
    函数体
}

先看一些比较简单的示例：
[]{
    std::cout << "hello lambda" << std::endl;
};

[]{
    std::cout << "hello lambda" << std::endl;
}();

注意看第一个和第二个  第一个lambda函数没有实际用处  第二个多了一个() 表示调用了该匿名函数

auto I = []{
    std::cout << "hello lambda" << std::endl;
};

I();   //调用了该匿名函数
auto I = ... 表示给lambda函数取什么昵称  方便后续调用

完整形式为 [...](...) mutable throwSpec -> retType {};
[...]叫作导入的符号 看到它就知道是lambda表达式了
(...)表示参数  因为lambda的行为像函数一样 当然就可以有参数了
mutable表示[...]中的数据可不可以被改写
throwspec 表示是否可以丢出异常
retType 描述lambda的返回类型
其中 mutable throwspec retType都是可选的  也可以不写  但只要有一个存在  就需要写()
[]中可以填 = 或 &, = 表示传值的方式   &表示传地址符号的方式 相当于取别名


*/