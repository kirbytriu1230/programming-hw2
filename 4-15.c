#include <stdio.h>
#include <math.h>

int main(void)
{
    int year;
    double ratePercent, amount;
    const double principal = 5000;

    for (ratePercent = 10.0; ratePercent <= 12.0; ratePercent += 0.5)
    {
        printf("Interest rate: %.1f%%\n", ratePercent);
        printf("%4s%20s\n", "Year", "Amount on deposit");
        for (year = 1; year <= 15; year++)
        {
            amount = principal * pow(1 + ratePercent / 100, year);
            printf("%4d%20.2f\n", year, amount);
        }
        putchar('\n');
    }
    return 0;
}
