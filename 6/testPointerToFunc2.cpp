// 函数指针作为函数返回值使用
// 暂未想到好的场景，先写出定义

#include <iostream>
using namespace std;

bool cmp(const int x, const int y)
{
    cout << x << " " << y << endl;
    return x >= y;
}

// 完整版声明
bool (*rf(bool, int, char))(const int, const int)
{
    return cmp;
}

// 简化版,using
using RetPointerFunc = bool (*)(const int, const int);
RetPointerFunc rf1(bool, int, char)
{
    return cmp;
}

// 尾置返回类型
// 编译器版本暂不支持
// auto rf2(bool, int, char) -> bool (*)(const int, const int);


int main()
{
    bool (*pf)(const int, const int);
    pf = rf(0, 0, 0);
    pf(1, 2);

    pf = rf1(0, 0, 0);
    pf(3, 0);

    // pf = rf2(0, 0, 0);
    // pf(5, 6);

    return 0;
}