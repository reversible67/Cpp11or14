#include <iostream>
#include <initializer_list>
#include <vector>

/*
auto关键字搭配for循环使用 可以时代码非常简洁和清晰
例如：
for(decl : coll)
{
    statement
}
*/
int main()
{
    for(int i : {2, 3, 5, 7, 9, 13, 17, 19})
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<double> vec {2.0, 3.2, 2.5, 7.8, 9.1, 10.3};
    for(auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 当加上&时 我们知道 相当于给变量取了别名 此时可以对vec中的元素进行改变
    for(auto & elem : vec)
    {
        elem *= 3;
        std::cout << elem << " ";
    }

    return 0;

}