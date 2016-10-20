//  
// 1
//             
//             1
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

void print(char[], char);

int main()
{
    printf("The byte of char is : %lu\n", sizeof(char));
    printf("The byte of short is : %lu\n", sizeof(short));
    
    // -1 10000001 11111110 11111111
    char i = 0xff;
    char l = 0x80;
    char j = 0x00;
    char k = 0x7f;
    
    printf("The num of 0xff is %d\n", i);
    printf("The num of 0x00 is %d\n", j);
    printf("The num of 0x7f is %d\n", k);
    printf("The num of 0x80 is %d\n", l);
    
    
    unsigned char ii = i;
    unsigned char ll = l;
    cout << short(ii) << endl;
    cout << short(ll) << endl;
    
    char a = 0xff;
    unsigned char ua = 0xff;
    print("0xff", a);
    print("0xff", ua);
    
    return 0;
}

void print(char chs[], char ch) 
{
    printf("The num of %s is %d\n", chs, ch);
}
