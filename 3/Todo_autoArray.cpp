// 具体怎么理解范围for语句中使用auto和多维数组，有待进一步挖掘细节
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    auto ai = i;
    auto &ri = i;
    auto *pi = &i;
    auto pti = &i;

    int arr1[3];
    int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    auto ar1 = arr1;//int *
    
    // 注意以下auto的区别，建议通过debug仔细察看变量类型
    auto ar2 = arr2;//int (*)[4]
    for (auto row : arr2) // row = arr2[0] = &arr2[0][0].即 int *
        cout << "row: " << row[1] << endl;
    
    // auto &row : arr2 避免被转换成指针。row类型为 int (&)[4]
    for (auto &row : arr2)
        for (auto col : row) 
            cout << col << endl;
    return 0;
}