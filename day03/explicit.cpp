#include <iostream>
#include <initializer_list>

/*
关键字explicit  翻译为:明白的 明确的
在构造函数前面加上explicit 就是在告诉编译器
我要明确的调用  不需要你给我做隐式的转换
*/
// C++2.0之前的explicit
struct Complex
{
    int real, imag;

    // 这种情况叫单一实参  因为你只需要指定一个参数即可  第二个参数是默认的
    // C++2.0之前的explicit 只支持单一实参  也就是当前这种情况 one argument
    // explicit
    Complex(int re, int im = 0)
    : real(re)
    , imag(im)
    {

    }

    Complex operator+(const Complex& x)
    {
        return Complex((real + x.real), (imag + x.imag));
    }

    void print()
    {
        std::cout << "real = " << real << " " << "imag = " << imag << std::endl;
    }
};

// C++2.0的explicit
class P
{
public:
    P(int a, int b)
    {
        std::cout << "P(int a, int b)" << std::endl;
    }

    P(std::initializer_list<int>)
    {
        std::cout << "P(initializer_list<int>)" << std::endl;
    }

    explicit
    P(int a, int b, int c)
    {
        std::cout << "explicit P(int a, int b. int c)" << std::endl;
    }
};

int main()
{
    // C++2.0之前的explicit
    Complex c1(12, 5);
    // 编译器'很聪明',编译器会隐式的将5转换为 5 + 0i;
    // 让编译器不那么聪明  必须在我显示地调用构造函数时 才会转为 不让整数5隐式的转换为5+0i
    // 所以在构造函数前面  加上explicit
    Complex c2 = c1 + 5;  //加上explicit之后  不会隐式转换  就会报错
    c1.print();
    c2.print();

    // C++2.0的explicit
    // 支持一个两个以上的实参  也开始提供explicit 禁止编译器做转换
    P p1 (77, 5);
    P p2 {77, 5};
    P p3 {77, 5, 42};
    P p4 = {77, 5};
    P p5 (77, 5, 42);
    return 0;
}