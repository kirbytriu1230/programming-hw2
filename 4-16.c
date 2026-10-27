#include <stdio.h>

int main(void)
{
    int pattern, row, column, stars, spaces;

    for (pattern = 0; pattern < 4; pattern++)
    {
        printf("(%c)\n", 'A' + pattern);
        for (row = 1; row <= 10; row++)
        {
            if (pattern == 0 || pattern == 3)
                stars = row;
            else
                stars = 11 - row;
            spaces = pattern >= 2 ? 10 - stars : 0;
            for (column = 0; column < spaces; column++)
                putchar(' ');
            for (column = 0; column < stars; column++)
                printf("%s", "*");
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
