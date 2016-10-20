#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a = 3, b = 4;
    
    // The type of c is int
    decltype(a) c;
    // The type of d is int &
    // decltype中的表达式不实际计算，所以a的值不变
    decltype(a = b) d = b;
    // ++b会发生计算，b的值加1
    auto x = ++b;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "x: " << x << endl;
    cout << (typeid(int*) == typeid(const int *const)) << endl;
    
    cout << typeid(const int *const).name() << endl;
    
    return 0;
}