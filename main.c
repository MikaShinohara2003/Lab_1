#include <stdio.h>

int cnt_brackets(char str[])
{
    int cnt = 0;
    int cnt_all = 0;
    int i = 0;
    while ((str[i]) && (cnt>=0))
    {
        if (str[i] == '(')
        {
            cnt++;
            cnt_all++;
        }
        else if (str[i] == ')')
        {
            cnt--;
            cnt_all++;
        }
        i++;
    }
    return cnt;
}

int main()
{
    char str_origin[50] = "(7-x)*(11+y)=77"; // баланс скобок (TRUE)
    //char str_origin[50] = "(7(-x)*(11+y)=77"; // количество '(' больше ')' (FALSE)
    //char str_origin[50] = "(7-x)*(11+)y)=77"; // количество ')' больше '(' (FALSE)
    //char str_origin[50] = "(7)-x)*(11+y)=77"; // ')' впереди '(' (FALSE)
    //char str_origin[50] = "7-x*11+y=77"; // скобок нет (NO BRACKETS)

    int res_cnt = cnt_brackets(str_origin);

    //if (cnt_all == 0)
    //{
    //    printf("No brackets\n\n");
    //}
    if (res_cnt == 0)
    {
        printf("TRUE: balance of brackets\n\n");
    }
    else
    {
        printf("FALSE: no balance of brackets\n\n");
    }

    return 0;
}
