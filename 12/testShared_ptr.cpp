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
    
    shared_ptr<int> p3 = make_shared<int>();// �����ݲ�����ֵ��ʼ��
    cout << "value of p3: " << *p3 << endl;
    
    int * pi3 = new int();// ֵ��ʼ����0
    int *pi4 = new int; // Ĭ�ϳ�ʼ����δ����
    cout << "value of pi3: " << *pi3 << endl;
    cout << "value of pi4: " << *pi4 << endl;
    return 0;
}