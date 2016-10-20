#include <iostream>
using namespace std;

int main()
{
    unsigned cnt = 42;
    cin >> cnt;
    int arr[cnt];

    constexpr unsigned sz = 20;
    int arr1[sz] = {0};

    int val = 0;
    for (int *p = arr; p < arr + cnt; ++val,++p) {
        *p = val;
    }

    for (int index = 0; index < cnt; ++index) {
        cout << arr[index] << " ";
    }
    cout << endl;

    for (int *p = arr1; p < arr1 + sz; ++p) {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}