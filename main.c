#include <stdio.h>

int check_brackets(char str[])
{
    int cnt = 0;
    char fl = '0';
    int i = 0;
    while ((str[i]) && (cnt>=0))
    {
        if (str[i] == '(')
        {
            cnt++;
            fl = '1';
        }
        else if (str[i] == ')')
        {
            cnt--;
            fl = '1';
        }
        i++;
    }

    if (fl == '0')
    {
        return -1;
    }
    else if (cnt == 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    char str_origin[50] = "(7-x)*(11+y)=77"; // баланс скобок (TRUE)
    //char str_origin[50] = "(7(-x)*(11+y)=77"; // количество '(' больше ')' (FALSE)
    //char str_origin[50] = "(7-x)*(11+)y)=77"; // количество ')' больше '(' (FALSE)
    //char str_origin[50] = "(7)-x)*(11+y)=77"; // ')' впереди '(' (FALSE)
    //char str_origin[50] = "7-x*11+y=77"; // скобок нет (NO BRACKETS)

    int res_cnt = check_brackets(str_origin);

    if (res_cnt == -1)
    {
        printf("No brackets\n\n");
    }
    else if (res_cnt == 0)
    {
        printf("TRUE: balance of brackets\n\n");
    }
    else
    {
        printf("FALSE: no balance of brackets\n\n");
    }

    return 0;
}
