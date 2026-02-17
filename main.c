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

    printf("%d\n", cnt);
    return 0;
}
