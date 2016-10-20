#include <iostream>

int main()
{
    std::cout << "Please Enter Two Numbers: "; // 用于提示用户输入两个数，且不换行
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The * of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;

    return 0;
}
