#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string str1 = "abc123345", str2 = "abc12345";
    char chr1[] = "abc123345", chr2[] = "abc12345";

    // 比较string对象
    if (str1 > str2)
        cout << str1 << ">" << str2 << endl;
    else if (str1 < str2)
        cout << str1 << "<" << str2 << endl;
    else
        cout << str1 << "=" << str2 << endl;
    
    // 比较char[], C类型字符串，以 "\0" 结尾
    if (strcmp(chr1, chr2) > 0)
        cout << chr1 << ">" << chr2 << endl;
    else if (strcmp(chr1, chr2) < 0)
        cout << chr1 << "<" << chr2 << endl;
    else
        cout << chr1 << "=" << chr2 << endl;
        
    return 0;
}