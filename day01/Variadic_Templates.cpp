#include <iostream>
#include <bitset>

void print() // 递归的出口
{

}
/*
Variadic Templates翻译为数量不定的模板参数，如果需要使用这个功能，
首先应在template处定义，如template<typename T, typename... Types>
*/
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
	std::cout << firstArg << std::endl;
	print(args...);  // 递归
}

int main()
{
	print(7.5, "hello", std::bitset<16>(377), 42);
	return 0;
}
/*
1.首先在template<typename T, typename... Types>中，在typename T这个类型之后，还有不定个类型，
所以在第二个typename后面加上... 表示后续还有不定个类型，然后统一用Types表示。

2.接下来在void print(const T& firstArg, const Types&... args)中，第一个参数名为firstArg，参数类型为T。
接下来表示还有不定个参数，参数名用args表示，类型由上述的Types统一表示，Types&...表示不定个参数.

3.最后有一个print(args...)，这一行代码表示继续调用print函数(自身)，args表示不定个参数，一直递归下去，
每次传递的参数个数也是不定个，但是不再包括firstArg，而是firstArg之后的所有参数，然后一直递归下去，
那我们思考一个问题？什么时候递归结束，我们想象一下临界条件，此时还剩一个参数，调用了print函数，
这个时候最后这个参数将作为firstArg，在执行完cout操作后，继续调用print，但是这次没有参数了，
所以我们需要额外定义一个空参数的print函数，作为递归的出口！

*/