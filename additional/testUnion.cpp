#include <iostream>
using namespace std;

union bits_32 {
    // 一个bits_32类型的变量共占32bits，可以把这部分内存解释成两种不同的东西：
    // 一个int类型，或者一个有4个char组成的结构体
    int value;
    struct {char c0, c1, c2, c3;} byte;
};

int main()
{
    union bits_32 num;
    num.value = 0x1f2f3f4f;
    unsigned val = 0xffffff00;
    cout << num.value << endl;
    cout << (unsigned)num.byte.c0%val << " " 
         << (unsigned)num.byte.c1%val << " " 
         << (unsigned)num.byte.c2%val << " " 
         << (unsigned)num.byte.c3%val << endl;

    return 0;
}