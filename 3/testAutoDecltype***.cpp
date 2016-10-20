#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    auto ia2 = ia; // 指针，int *
    ia2 = ia + 2;

    decltype(ia) ia3; // 数组，int [10]
    // end() 属于 <iterator>，返回数组的尾后指针
    for (int *p = ia, *q = ia3; p != end(ia) && q != end(ia3); ++p,++q)
        *q = *p;
    
    for (auto elem : ia3)
        cout << elem << " ";
    cout << endl;

    return 0;
}