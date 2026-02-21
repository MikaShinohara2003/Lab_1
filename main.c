#include <stdio.h>

int main()
{
    char str[50];
    scanf("%[^\n]", str);

    int i = 0;
    int cnt = 0;
    char first_w = str[0];
    char second_w;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            second_w = str[i-1];
            if (first_w == second_w)
            {
                cnt++;
            }
            first_w = str[i+1];
        }
        i++;
    }

    printf("%d\n\n", cnt);
    return 0;
}
