#include <iostream>
#include <string>
#include <memory>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

int main()
{
    shared_ptr<std::vector<string>> p1;
    p1 = std::make_shared<std::vector<string>>();
    string *p2 = nullptr;
    
    int x = 1;
    shared_ptr<int> pi1 = std::make_shared<int>(2);
    
    cout << pi1 << " " << pi1.get() << endl;
    cout << "x: " << &x << endl;
    
    shared_ptr<int> p3 = make_shared<int>();// 不传递参数，值初始化
    cout << "value of p3: " << *p3 << endl;
    
    int * pi3 = new int();// 值初始化，0
    int *pi4 = new int; // 默认初始化，未定义
    cout << "value of pi3: " << *pi3 << endl;
    cout << "value of pi4: " << *pi4 << endl;
    return 0;
}