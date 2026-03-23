#include <stdio.h>

int strToNum(char* str, int i)
{
    int num = 0;
    int k = 8 + i;

    while (str[i])
    {
        if (i > k)
        {
            return -2;
        }

        if ((str[i] < '0') || (str[i] > '9'))
        {
            return -1;
        }

        num = num*10 + (str[i]-'0');
        i++;
    }

    return num;
}

int main()
{
    char str_origin[50] = "120"; // 120
    //char str_origin[50] = "-120"; // -120
    //char str_origin[50] = "+120"; // 120
    //char str_origin[50] = "000120"; // 120
    //char str_origin[50] = "-000120"; // -120
    //char str_origin[50] = "+000120"; // 120
    //char str_origin[50] = "+0"; // 0
    //char str_origin[50] = "-0"; // 0
    //char str_origin[50] = "-"; // can't be converted
    //char str_origin[50] = "+"; // can't be converted
    //char str_origin[50] = "12v0"; // can't be converted
    //char str_origin[50] = "999999999"; // 999999999
    //char str_origin[50] = "-999999999"; // -999999999
    //char str_origin[50] = "9999999999"; // too big number

    int i = 0;
    char flag_minus = '0';

    if ((str_origin[0] == '-') && (str_origin[1] != '\0'))
    {
        i++;
        flag_minus = '1';
    }
    else if ((str_origin[0] == '+') && (str_origin[1] != '\0'))
    {
        i++;
    }

    int res_num = strToNum(str_origin, i);

    if (res_num >= 0)
    {
        if (flag_minus == '1')
        {
            res_num = 0 - res_num;
        }
        printf("%d\n\n", res_num);
    }
    else if (res_num == -1)
    {
        printf("Symbols can't be converted\n\n");
    }
    else
    {
        printf("Too big number\n\n");
    }

    return 0;
}
