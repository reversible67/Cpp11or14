#include <iostream>

/*
1.实际开发中，避免产生“野指针”最有效的方法，就是在定义指针的同时完成初始化操作，即便该指针的指向尚未明确，也要将其初始化为空指针
2.所谓“野指针”，又称“悬挂指针”，指的是没有明确指向的指针。野指针往往指向的是那些不可用的内存区域，
这就意味着像操作普通指针那样使用野指针（例如 &p）时，极可能导致程序发生异常。
C++98/03 标准中，将一个指针初始化为空指针的方式有 2 种：
int *p = 0;
int *p = NULL; //推荐使用
可以看到，我们可以将指针明确指向 0（0x0000 0000）这个内存空间。一方面，明确指针的指向可以避免其成为野指针；
另一方面，大多数操作系统都不允许用户对地址为 0 的内存空间执行写操作，若用户在程序中尝试修改其内容，则程序运行会直接报错。
C++ 中将 NULL 定义为字面常量 0，虽然能满足大部分场景的需要，但个别情况下，它会导致程序的运行和我们的预期不符。例如：
#include <iostream>
using namespace std;
void isnull(void *c){
    cout << "void*c" << endl;
}
void isnull(int n){
    cout << "int n" << endl;
}
int main() {
    isnull(0);
    isnull(NULL);
    return 0;
}
运行结果：
int n
int n
对于 isnull(0) 来说，显然它真正调用的是参数为整形的 isnull() 函数；
而对于 isnull(NULL)，我们期望它实际调用的是参数为 void*c 的 isnull() 函数，但观察程序的执行结果不难看出，并不符合我们的预期。
C++ 98/03 标准中，如果我们想令 isnull(NULL) 实际调用的是 isnull(void* c)，就需要对 NULL（或者 0）进行强制类型转换：
isnull( (void*)NULL );
isnull( (void*)0 );
*/
void isnull(int n)
{
    std::cout << "int n" << std::endl;
}

void isnull(void *c)
{
    std::cout << "void * c" << std::endl;
}

int main()
{
    isnull(0);             // 输出 int n
    // isnull(NULL);       // 输出 int n
    isnull((void *) 0);    // 输出 void * c
    isnull((void *) NULL); // 输出 void * c
    isnull(nullptr);       // 输出 void * c
    return 0;
}