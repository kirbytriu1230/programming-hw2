#include <stdio.h>

int main(void)
{
    int length, breadth, row, column;

    printf("Enter length and breadth: ");
    if (scanf("%d %d", &length, &breadth) != 2 || length < 1 || breadth < 1)
        return 1;

    for (row = 1; row <= length; row++)
    {
        for (column = 1; column <= breadth; column++)
        {
            if (row == 1 || row == length || column == 1 || column == breadth)
                putchar('+');
            else
                putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
