#include <iostream>
#include <initializer_list>
using namespace std;

int add(initializer_list<int> il) {
    int total = 0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        total += *beg;
    return total;
}

int main()
{
    cout << add({1,2,3,4,5}) << endl;

    return 0;
}