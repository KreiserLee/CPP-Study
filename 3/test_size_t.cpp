#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = {0};
    // 在使用数组下标的时候通常将其定义为 size_t 类型.size_t 类型是一种机器相关的无符号类型
    size_t len = end(arr1) - begin(arr1);
    cout << "size_t: len of arr1 is " << len << ". sizeof(size_t) is "  << sizeof(size_t) << endl; 
    
    int v = 0;
    // auto val 是in`t型变量，赋值时拷贝赋值
    for (auto val : arr1) {
        val = v++;
    }

    int arr2[10] = {};
    v = 0;
    // auto &val 是int型引用，对val赋值时相当于对arr2数组元素赋值
    for (auto &val : arr2) {
        val = v++;
    }

    for (size_t i = 0; i != 10; ++i) {
        cout << *(arr1 + i) << "    " << *(arr2 + i) <<  endl;
    }

    return 0;
}