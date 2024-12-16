#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>

int main()
{
    //
    printf("This character \0 is used to determine a string\n");
    // 定义字符串的数组一定要比字符串多1，用于添加\0,
    // 不然就会被后面的变量覆盖掉,导致前面的变量泄露
    char test[3] = "str";
    char tes[1] = "y";
    printf("============Test for Null(\\0)==============\n");
    printf("\n%s %s\n\n", test, tes);

    char longStr[50] = "Hi";
    unsigned int count = 0;
    while (longStr[count] != '\0')
        ++count;
    printf("============Test for Manul Defined strlen()==============\n");
    printf("String length: %i\n\n", count);

    // 计算字符串长度
    char test_lens[] = "I am a quite long long string.";
    printf("============Test for strlen()==============\n");
    printf("\"%s\" has length of %zu\n\n", test_lens, strlen(test_lens));

    // 拷贝字符串
    char test_copy[] = "I am a monkey";
    char test_copy_copy[50];
    printf("============Test for strcpy()==============\n");
    if (strcpy(test_copy_copy, test_copy))
        printf("Copy Sucessful! \nOriginal: %s, \nNew: %s.\n\n", test_copy, test_copy_copy);

    printf("============Test for strcat()==============\n");
    char s1[50] = "I am a pen\n";
    char s2[50] = "I am an apple\n";
    char s3[] = "AppelPen!\n\n";

    strcat(s1, s2);
    printf("%s", s1);
    strcat(s1, s3);
    printf("%s", s1);

    printf("============Test for nested strcat()==============\n");
    char s4[50] = "I am a pen\n";
    strcat(strcat(s4, s2), s3);
    printf("%s", s4);

    return 0;
}