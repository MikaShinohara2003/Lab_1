#include <stdio.h>

int main()
{
    //char str[50] = "sts."; // первый символ равен последнему (1)
    //char str[50] = "stsk."; // первый символ не равен последнему (0)
    //char str[50] = "sts in sts."; // пробелы между словами (2)
    //char str[50] = "sts,in,sts."; // запятые между словами (2)
    //char str[50] = "sts in,sts."; // или пробел, или запятая между словами (2)
    //char str[50] = "sts in   sts."; // несколько пробелом между словами (2)
    //char str[50] = "sts,,,,,in,sts."; // несколько запятых между словами (2)
    //char str[50] = "sts ,,,,  ,, in,,   ,,sts."; // несколько запятых и несколько пробелов между словами(2)
    //char str[50] = "  sts in sts."; // несколько пробелов впереди(2)
    char str[50] = ",,,sts in sts."; // несколько пробелов впереди(2)

    int i = 0;
    int cnt = 0;
    char first_w;
    char second_w;
    while ((str[i] == ' ') || (str[i] == ','))
    {
        i++;
    }
    first_w = str[i];
    while (str[i] != '.')
    {
        if ((str[i] == ' ') || (str[i] == ','))
        {
            second_w = str[i-1];
            if (first_w == second_w)
            {
                cnt++;
            }
            if ((str[i+1] != ' ') && (str[i+1] != ','))
            {
                first_w = str[i+1];
            }
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
