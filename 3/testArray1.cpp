#include <iostream>
#include <string>
using namespace std;

int main()
{
    const unsigned sz = 3;

    int ial[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};
    string a4[3] = {"hi", "bye"};
    
    for (string *p = a4; p < a4 + 3; ++p)
        cout << *p << endl;
    return 0;
}