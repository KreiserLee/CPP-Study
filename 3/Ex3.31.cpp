#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v, v1;
    for (int index = 0; index != 10; ++index)
        v.push_back(index);
        
    // vector 对象直接用 ＝ 拷贝赋值
    v1 = v;
    vector<int>::iterator beg = v1.begin();
    while(beg != v1.end())
        cout << *beg++ << endl;

    return 0;
}