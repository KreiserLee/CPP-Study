// Input a and b, then output integer in [a, b)...
#include <iostream>

int main()
{
    int a, b, val;
    std::cout << "Input two Integer a and b: ";
    std::cin >> a >> b;
    
    val = a;
    while (val < b) {
        std::cout << val << std::endl;
        ++val;
    }
    return 0;
}

