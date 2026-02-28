#include <stdio.h>

int strToNum(char str[])
{

}

int main()
{
    char str[50] = "-120";

    int num = 0;
    int i = 0;
    char flag = '1';
    char flag_minus = '0';

    if ((str[0] == '-') && (str[1] != '\0'))
    {
        i++;
        flag_minus = '1';
    }
    if ((str[0] == '+') && (str[1] != '\0'))
    {
        i++;
    }

    while ((str[i]) && (flag == '1'))
    {
        if ((str[i] < '0') || (str[i] > '9'))
        {
            flag = '0';
        }
        else
        {
            num = num*10 + (str[i]-'0');
        }
        i++;
    }

    if (flag_minus == '1')
    {
        num = 0 - num;
    }

    if (flag == '1')
    {
        printf("%d\n", num);
    }
    else
    {
        printf("Symbols can't be converted\n");
    }
    return 0;
}
