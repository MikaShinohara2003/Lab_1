#include <stdio.h>

int main()
{
    char str[50];
    scanf("%s", str);

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

    if (cnt_all == 0)
    {
        printf("No brackets\n\n");
    }
    else if (cnt == 0)
    {
        printf("TRUE: balance of brackets\n\n");
    }
    else
    {
        printf("FALSE: no balance of brackets\n\n");
    }

    return 0;
}
