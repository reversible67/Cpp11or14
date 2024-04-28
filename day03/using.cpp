#include <iostream>

/*
在C++11中 using还可以用来定义别名(alias)，例如：
using ll = long long;
有了这行代码 在后续就可以用ll 代替 long long类型
*/
using ll = long long;

int main()
{
    ll res = 0;
    std::cout << "size of res = " << sizeof(res) << std::endl;

    return 0;
}