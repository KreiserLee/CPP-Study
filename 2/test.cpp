#include <iostream>
using namespace std;

int main()
{
    int i = 1, &j = i;
    int *p = &i;
    cout << "Hello, world!" << endl;

    cout << "first" << endl;
    return 0;
}