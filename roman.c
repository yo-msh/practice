#include <stdio.h>
// #define I 1
// #define V 5
// #define X 10
// #define L 50
// #define C 100
// #define M 1000

int rom2dec(char *p, int n)
{
    int i, j, m, sum = 0;
    char ch;

    for (i = 0; i < n; i++)
    {
        ch = *(p + i);

        switch (ch)
        {
        case 'M':
            sum += 1000;
            break;

        case 'C':
            if (*(p + i + 1) == 'M')
                sum -= 100;
            else
                sum += 100;
            break;

        case 'L':
            sum += 50;

            break;

        case 'X':
            if (*(p + i + 1) == 'L' || *(p + i + 1) == 'C')
                sum -= 10;
            else
                sum += 10;
            break;

        case 'V':
            sum += 5;
            break;

        case 'I':
            if (*(p + i + 1) == 'V' || *(p + i + 1) == 'X')
                sum -= 1;
            else
                sum += 1;
            break;
        }
    }

    return sum;
}

int main()
{
    int i, n, value;
    printf("enter roman value:\n");
    char a[10];
    gets(a);

    for (n = 0; a[n] != '\0'; n++)
        ;

    for (i = 0; i < n; i++)
    {
        if (!(a[i] >= 'A' && a[i] <= 'Z'))
           { printf("not all char are in upper:");
            return 0;
    }
    }

    value = rom2dec(a, n);

    printf("%d", value);
    return 0;
}
