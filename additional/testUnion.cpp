#include <iostream>
using namespace std;

union bits_32 {
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