#include <stdio.h>

// 0 - OK
// 1 - invalid symbols
// 2 - no dot
// 3 - no words

char check_str(char* str)
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
                return '1';
            }
        }

        if (str[i] == '.')
        {
            if (cnt_ltr != 0)
            {
                return '0';
            }
            return '3';
        }

        i++;
    }
    return '2';
}

int cnt_w_same_ltr(char* str)
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

    return cnt;
}

int main()
{
    //char str_origin[50] = "sts."; // first symbol equal last (1)
    //char str_origin[50] = "stsk."; // first symbol not equal last (0)
    //char str_origin[50] = "sts in sts."; // spaces between words (2)
    //char str_origin[50] = "sts,in,sts."; // commas between words (2)
    //char str_origin[50] = "sts in,sts."; // space or comma between words (2)
    //char str_origin[50] = "sts in   sts."; // some spaces between words (2)
    //char str_origin[50] = "sts,,,,,in,sts."; // some commmas between words (2)
    //char str_origin[50] = "sts ,,,,  ,, in,,   ,,sts."; // some commas and some spaces between words (2)
    //char str_origin[50] = "  sts in sts."; // some spaces in beginning (2)
    //char str_origin[50] = ",,,sts in sts."; // some commas in beginning (2)
    //char str_origin[50] = "sts in sts"; // string without dot (error: no dot)
    //char str_origin[50] = "s^ts."; // (error: invalid symbols)
    //char str_origin[50] = "."; // (error: no words)
    //char str_origin[50] = " ,      "; // (error: no dot)
    //char str_origin[50] = " ,      ."; // (error: no words)
    char str_origin[50] = "sts in sts. krkrk"; // dot in the middle of sentence (2)

    char res_check = check_str(str_origin);

    if (res_check == '0')
    {
        int cnt_w = cnt_w_same_ltr(str_origin);

        printf("Number of words: %d\n\n", cnt_w);
    }
    else if (res_check == '1')
    {
        printf("ERROR: Invalid symbols in sentence!\n\n");
    }
    else if (res_check == '2')
    {
        printf("ERROR: No dot in sentence!\n\n");
    }
    else
    {
        printf("ERROR: No words!\n\n");
    }

    return 0;
}
