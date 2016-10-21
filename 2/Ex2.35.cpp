#include <iostream>
#include <string>
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    auto p1 = &i;
    const auto j2 = i, &k2 = i;
    
    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    cout << typeid(k).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(j2).name() << endl;
    cout << typeid(k2).name() << endl;
    cout << typeid(p1).name() << endl;
    
    cout << *p << endl;
    cout << *p1 << endl;
    
    return 0;
}
