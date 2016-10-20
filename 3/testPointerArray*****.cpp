#include <iostream>
using namespace std;

int main()
{
    int arri[10];
    int *ptri[10];  // 数组，int型指针数组
    // int &refip[10]; // 错误，引用不是对象，没有引用数组
    int (*ptrarr)[10] = &arri; // 指针，指向一个 int[10] 数组的指针
    int (&refarr)[10] = arri; // 引用，绑定一个 int[10] 对象的引用；必须在定义时初始化

    arri[1] = 10;

    refarr[2] = 20;

    cout << "The End of testPointerArrry!" << endl; 
    return 0;
}