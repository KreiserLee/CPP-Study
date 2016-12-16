#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {}, *p = &arr[90];

    // arr 是一个数组，但是可以用指针解引用的形式使用；
    for (int i = 0; i != 100; ++i)
        *(arr + i) = i;
    // p 是一个int型指针，可以通过下标运算取值；
    for (int i = 0; i != 10; ++i)
        cout << p[i] << endl;

    return 0;
}