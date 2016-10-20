#include <iostream>
using namespace std;

int main()
{
    int a[10];

    auto x = a; // 指针，int * 指向数组首元素
    auto y = &a; // 指针，int (*)[10] 指向数组(整体)
    auto z = &a[0]; // 指针，int * 指向数组首元素

    auto _x = *a; // 整型，数组首元素的拷贝

    int n = sizeof(a); // 数组的内存大小
    int m = sizeof(a[0]);  // 数组元素的内存大小

    return 0;
}