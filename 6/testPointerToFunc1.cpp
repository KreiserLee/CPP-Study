// 函数指针作为形参
// 使用typedef，using以及decltype，简化函数指针的定义

#include <iostream>
#include <string>
using namespace std;

// 带函数指针类型形参的函数定义
int getBigger(const int a, const int b, bool (*cmp)(const int, const int))
{
    return cmp(a, b) ? a : b;
}
// 直接将形参定义成函数，编译器会自动地将其转换为指向函数的指针
int getSmaller(const int a, const int b, bool cmp(const int, const int))
{
    return cmp(a, b) ? b : a;
}

// 将被作为实参传递的函数
bool intCompare(const int x, const int y)
{
    return x >= y;
}

int main()
{
    // 调用带函数指针的函数,直接使用函数名
    int a = 100, b = 200;
    cout << "The bigger one of " << a << " and " << b << " is : " << getBigger(a, b, intCompare) << endl;

    // 使用 typedef 简化函数指针的定义
    // PointerToFunction 是 bool (*)(const int, const int) 类型的别名
    typedef bool (*PointerToFunction)(const int, const int);
    PointerToFunction pf = intCompare;
    cout << "The smaller one of " << a << " and " << b << " is : " << getSmaller(a, b, pf) << endl;

    // 使用 using 简化函数指针的定义
    // PointerToFunction1 是 bool (*)(const int, const int) 类型的别名
    using PointerToFunction1 = bool (*)(const int, const int);
    PointerToFunction1 pf1 = intCompare;
    cout << "The smaller one of " << a << " and " << b << " is : " << getSmaller(a, b, pf1) << endl;

    // 使用decltype
    // PS.decltype 作用于某个函数时，它返回函数类型而非函数指针
    // 下面Func是 bool (const int, const int) 类型的别名
    typedef decltype(intCompare) Func;
    
    // 错误 error: non-object type 'Func' (aka 'bool (const int, const int)') is not assignable
    // Func pf2;
    // pf2 = intCompare;

    // 显示声明指针类型
    Func *pf2 = intCompare;
    cout << "The bigger one of " << a << " and " << b << " is : " << getBigger(a, b, pf2) << endl;

    return 0;
}