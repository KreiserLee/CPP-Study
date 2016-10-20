#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int i = 0, &r = i, *p1 = &r;
    int *p = nullptr, *q = &i;
    
    if(p)
        cout << "p pass!" << endl;
    if(q)
        cout << "q pass!" << endl;
    if(*q)
        cout << "*q pass!" << endl;
    
    i = 10;
    cout << i << endl;
    cout << r << endl;
    cout << *p1 << endl;
    
    return 0;
}