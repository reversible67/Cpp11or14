#include <iostream>
#include <array>
/*
array是C++11新增的容器，效率与普通数据相差无几，比vector效果要高，自身添加了一些成员函数
和其他容器不同，array容器大小是固定的，无法动态的扩展或收缩，只允许访问或替换存储的元素
array的出现 是为了替代C风格的数组

注意：array的使用是要在std命名空间里
*/

int main(){
    // 声明与初始化
    // 声明一个大小为100的int型数组，元素的值不确定
    // std::array<int, 100> a;
    // 声明一个大小为100的int型数组，初始值均为0
    // std::array<int, 100> a{};
    // 声明一个大小为100的int型数组，初始化部分值
    // std::array<int, 100> a{1, 2, 3};
    // 或者可以使用等号进行初始化
    // std::array<int, 100> a = {1, 2, 3};
    // 修改元素
    std::array<int, 4>a = {1, 2, 3, 4};
    a[0] = 4;
    // 下标访问
    for(int i = 0; i < 4; ++i){
       std::cout << a[i] << std::endl; 
    }

    // 利用auto访问
    for(auto i : a){
        std::cout << i << std::endl;
    }

    // 迭代器访问
    auto it = a.begin();
    for(; it != a.end(); ++it){
        std::cout << *it << std::endl;
    }

    // get方法访问
    std::get<1>(a) = 5;
    std::cout << a[1] << std::endl; 

    // at函数 获取对应下标处的值
    int res = a.at(1) + a.at(2);
    std::cout << "res = " << res << std::endl;
}