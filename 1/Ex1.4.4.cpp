#include <iostream>

int main()
{
    int currVal, val;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (currVal == val)
                ++cnt;
            else {
                std::cout << currVal << " occurs " 
                          << cnt << " times." << std::endl;
                cnt = 1;
                currVal = val;
            }
        }
        std::cout << currVal << " occurs " 
                  << cnt << " times." << std::endl;
    } else {
        std::cout << "No Data!" << std::endl;
    }
    
    return 0;
}