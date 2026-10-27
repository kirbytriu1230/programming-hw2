#include <stdio.h>

int main(void)
{
    int row, column, width;

    for (row = 1; row <= 9; row++)
    {
        width = row <= 5 ? row : 10 - row;
        for (column = 0; column < 5 - width; column++)
            putchar(' ');
        for (column = 0; column < 2 * width - 1; column++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
