#include <stdio.h>

// 0 - ОК
// 1 - недопустимые символы
// 2 - отсутствует точка
// 3 - нет слов

int check_str(char str[])
{
    int i = 0;
    int cnt_ltr = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] != ',') && (str[i] != '.'))
        {
            cnt_ltr++;
            if ((str[i] < 'A') || ((str[i] > 'Z') && (str[i] < 'a')) || (str[i] > 'z'))
            {
                return 1;
            }
        }

        if (str[i] == '.')
        {
            if (cnt_ltr != 0)
            {
                return 0;
            }
            return 3;
        }

        i++;
    }
    return 2;
}

int cnt_w_same_ltr(char str[])
{
    int i = 0;
    int cnt = 0;
    char first_w;
    char second_w;
    while ((str[i] == ' ') || (str[i] == ','))
    {
        i++;
    }
    first_w = str[i];
    i++;
    while (str[i] != '\0')
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

    return cnt;
}

int main()
{
    char str_origin[50] = "sts."; // первый символ равен последнему (1)
    //char str_origin[50] = "stsk."; // первый символ не равен последнему (0)
    //char str_origin[50] = "sts in sts."; // пробелы между словами (2)
    //char str_origin[50] = "sts,in,sts."; // запятые между словами (2)
    //char str_origin[50] = "sts in,sts."; // или пробел, или запятая между словами (2)
    //char str_origin[50] = "sts in   sts."; // несколько пробелом между словами (2)
    //char str_origin[50] = "sts,,,,,in,sts."; // несколько запятых между словами (2)
    //char str_origin[50] = "sts ,,,,  ,, in,,   ,,sts."; // несколько запятых и несколько пробелов между словами(2)
    //char str_origin[50] = "  sts in sts."; // несколько пробелов впереди(2)
    //char str_origin[50] = ",,,sts in sts."; // несколько запятых впереди(2)
    //char str_origin[50] = "sts in sts"; // строка без точки (error: no dot)
    //char str_origin[50] = "s^ts."; // недопустымые символы (error: invalid symbols)
    //char str_origin[50] = "."; // нет слов (error: no words)
    //char str_origin[50] = " ,      "; // нет точки (error: no dot)
    //char str_origin[50] = " ,      ."; // нет слов (error: no words)

    int res_check = check_str(str_origin);

    if (res_check == 0)
    {
        int cnt_w = cnt_w_same_ltr(str_origin);

        printf("Number of words: %d\n\n", cnt_w);
    }
    else if (res_check == 1)
    {
        printf("ERROR: Invalid symbols in sentence!\n\n");
    }
    else if (res_check == 2)
    {
        printf("ERROR: No dot in sentence!\n\n");
    }
    else
    {
        printf("ERROR: No words!\n\n");
    }

    return 0;
}
