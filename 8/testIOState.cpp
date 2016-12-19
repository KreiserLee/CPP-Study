#include <iostream>
using namespace std;

int main()
{
    cout << cin.rdstate() << endl;
    cout << cin.good() << endl;
    cout << cin.fail() << endl;
    int x;
    
    cin >> x;
    
    cout << cin.rdstate() << endl;
    cout << cin.good() << endl;
    cout << cin.fail() << endl;
    
    cout << "1" << endl;
    cout << "2" << ends;
    cout << "3" << flush;
    return 0;
}