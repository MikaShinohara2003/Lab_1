#include <stdio.h>

int main()
{
    char str[50];
    scanf("%s", str);

    int num = 0;
    int i = 0;
    while (str[i])
    {
        num = num*10 + (str[i]-'0');
        i++;
    }

    printf("%d\n", num);
    return 0;
}
