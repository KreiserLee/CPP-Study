#include <iostream>
using namespace std;

int main()
{
    // typedef 定义类型别名，和声明同样的类型
    typedef int array[4];
    array arr = {0,1,2,3};
    for (int index = 0; index != 4; ++index)
        cout << arr[index] << endl;

    // pointer是int ＊类型，属于声明语句中的基本类型；声明指针时，声明符中不需要额外的＊
    typedef int * pointer;
    pointer p1 = arr, p2 = arr + 1;
    cout << *p1 << " " << *p2 << endl;

    // using 定义类型别名
    using arr1 = char[100];
    arr1 chr = "Hello, world!";
    cout << chr << endl; 
    return 0;
}