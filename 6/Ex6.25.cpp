#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) //char *argv[] <==> char **argv
{
    string s1(argv[1]), s2(argv[2]);
    cout << s1 + s2 << endl;

    string s;
    // 数组名单独使用表示指向数组首元素的指针，此处即为指向指针的指针 char**
    char **beg = argv;
    // argv 最后一个元素之后的指针为0(=0)
    while (*beg)
        s += *beg++;
    
    cout << "The Total of main : " << s << endl;
    // 程序名作为argv数组的第一个元素
    cout << "The number of main : " << argc << endl;

    return 0;
}