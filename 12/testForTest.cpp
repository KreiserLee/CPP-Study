#include <iostream>
#include <string>

int main()
{
    string *const p = new string[n]; // ����n����string
    string s;
    string *q = p; // qָ���һ��string
    while (cin >> s && q != p + n)
        *q++ = s;
    const std::size_t size = p - q; // ��ȡ��string����
    
    return 0;
}