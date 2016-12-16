#include <iostream>
#include <string>
using namespace std;

char &get_val(string & str, string::size_type ix) {
    return str[ix];
}

int main()
{
    string s = "hello, world!";
    cout << s << endl;
    // 返回的是s的首字符的引用，改变其返回值即是改变s本身
    get_val(s, 0) = 'H';
    cout << s << endl;
    return 0;
}