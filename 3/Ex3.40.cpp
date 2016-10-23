#include <string.h>
#include <stdio.h>

int main()
{
    char a1[100] = "Hello, ", a2[100] = "world!", a3[100];
    // 将a1数组中的字符串拷贝到a3中；
    strcpy(a3, a1);
    // 将a1数组中的字符串拷贝到a3已有字符串的后面；
    strcat(a3, a2);
    printf("%s\n", a3);

    return 0;
}