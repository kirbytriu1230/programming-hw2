#include <stdio.h>

int main(void)
{
    double sales;

    printf("Enter sales in dollars (-1 to end): ");
    while (scanf("%lf", &sales) == 1 && sales != -1)
    {
        if (sales < 0) return 1;
        printf("Salary is $%.2f\n\n", 200 + 0.09 * sales);
        printf("Enter sales in dollars (-1 to end): ");
    }
    return 0;
}
