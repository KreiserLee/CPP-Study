#include <iostream>
using namespace std;

int main()
{
    int ia[3][4] = {0};
    int arr[10][20][30] = {0};

    // 赋值
    // 用指针遍历数组，并给数组赋值
    int val = 0;
    for (int (*p)[4] = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            *q = val++;
    
    // 用指针遍历三维数组，并给数组元素赋值
    val = 0;
    for (int (*p)[20][30] = arr; p != arr + 10; ++p)
        for (int (*q)[30] = *p; q != *p + 20; ++q)
            for (int *r = *q; r != *q + 30; ++r)
                *r = val++;

    return 0;
}