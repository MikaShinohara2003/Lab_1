#include <stdio.h>

int main()
{
    char str[50];
    scanf("%s", str);

    int num = 0;
    int i = 0;
    char flag = '1';
    while ((str[i]) || (flag == '1'))
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
