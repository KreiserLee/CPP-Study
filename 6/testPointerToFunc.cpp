// 函数指针基础：定义，赋值，使用（调用函数）

#include <iostream>
#include <string>
using namespace std;

bool lengthCompare(const string &s1, const string &s2) 
{
    cout << "In lengthCompare Function!" << endl;
    return s1 >= s2;
}

// lengthCompare 的重载函数
void lengthCompare(int a) 
{
    cout << "In another function of lengthCompare!" << endl;
}

int main()
{   
    // First 定义
    // 定义函数指针,pf 是一个指针，指向一个形参列表为(const string&, const string&)的函数
    // 的指针，这个函数返回一个bool型变量
    bool (*pf)(const string&, const string&);
    void (*pf1)(int);

    // 函数指针的使用
    
    // Second 赋值
    // 函数指针赋值,下面两种赋值方式等价。当函数名作为值使用时，自动地转换成指向函数的指针。
    // 使用函数名赋值
    pf = lengthCompare;
    // 重载函数的指针
    // pf1指向第二个函数，由定义决定，编译器自动匹配
    pf1 = lengthCompare;
    // 使用取地址符
    pf = &lengthCompare;

    // Third 调用
    // 通过函数指针调用函数
    // 第一种方式，直接使用（不解引用）指针调用其所指函数
    bool b1 = pf("Hello,world!", "hello,world!");
    // 第二种方式，使用解引用符调用所指函数
    bool b2 = (*pf)("Hello,world!", "hello,world!");
    // PS. 直接使用函数本身
    bool b3 = lengthCompare("Hello,world!", "hello,world!");
    // 重载函数的函数调用
    pf1(1);

    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;
    return 0;
}