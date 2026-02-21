#include <stdio.h>

int main()
{
    char str[50];
    scanf("%[^\n]", str);
    printf("%s\n\n", str);
    return 0;
}
