#include <iostream>
using namespace std;

int main()
{
    int p = 0,q = 100;
    // p++ = q++; // 错误, p++ 不能用作lvalue;
    // q++ 过程：1.创建临时变量，将q的值拷贝给它；2.将q本身的值＋1；3.返回临时变量的值
    // q++; <==> tmp = q,q = q + 1,tmp; 上述两个表达式是等价的
    ++p = q++;
    cout << p << " " << q << endl;

    p = 0;
    cout << (p++) << endl;
    p = 0;
    int tmp;
    cout << (tmp = p,p = p + 1,tmp) << endl;
    return 0;
}