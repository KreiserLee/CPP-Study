#include <iostream>
#include <string>

int main()
{
    string *const p = new string[n]; // 构造n个空string
    string s;
    string *q = p; // q指向第一个string
    while (cin >> s && q != p + n)
        *q++ = s;
    const std::size_t size = p - q; // 读取的string数量
    
    return 0;
}