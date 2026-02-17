#include <stdio.h>

int main()
{
    char str[50];
    scanf("%s", str);

    int cnt = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            cnt++;
        }
        else if (str[i] == ')')
        {
            cnt--;
        }
        i++;
    }

    if (cnt == 0)
    {
        printf("TRUE: equal number of brackets\n\n");
    }
    else if (cnt > 0)
    {
        printf("FALSE: opened brackets > closed brackets\n\n");
    }
    else
    {
        printf("FALSE: opened brackets < closed brackets\n\n");
    }

    return 0;
}
