// 20161015 验证各数据类型所占内存（字节）
#include <iostream>
#include <stdio.h>

int main()
{
    char out[] = "The byte of %s is : %d\n";
    
    printf(out, "bool", sizeof(bool));
    printf(out, "char", sizeof(char));
    printf(out, "wchar_t", sizeof(wchar_t));
    printf(out, "char_t16", sizeof(char16_t));
    printf(out, "char32_t", sizeof(char32_t));
    printf(out, "short", sizeof(short));
    printf(out, "int", sizeof(int));
    printf(out, "long", sizeof(long));
    printf(out, "long long", sizeof(long long));
    printf(out, "float", sizeof(float));
    printf(out, "double", sizeof(double));
    printf(out, "long double", sizeof(long double));
    
    return 0;
}