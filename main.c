#include <stdio.h>

int main()
{
    char str[50] = "sts."; // первый символ равен последнему
    //char str[50] = "stsk."; // первый символ не равен последнему
    //char str[50] = "sts in sts."; // пробелы между словами
    //char str[50] = "sts,in,sts."; // запятые между словами
    //char str[50] = "sts in,sts."; // или пробел, или запятая между словами

    int i = 0;
    int cnt = 0;
    char first_w = str[0];
    char second_w;
    while (str[i] != '.')
    {
        if ((str[i] == ' ') || (str[i] == ','))
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
    second_w = str[i-1];
    if (first_w == second_w)
    {
        cnt++;
    }

    printf("Number of words: %d\n\n", cnt);
    return 0;
}
