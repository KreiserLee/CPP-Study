#include <iostream>
#include <string>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;

int main()
{
    int *x = new int(11);
    unique_ptr<int> p1(x);
    cout << p1.get() << " " << *p1 << endl;
    cout << x << " " << p1.get() << endl;
    
    return 0;
}