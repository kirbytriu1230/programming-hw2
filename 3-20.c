#include <stdio.h>

int main(void)
{
    double hours, rate, salary;

    printf("Enter # of hours worked (-1 to end): ");
    while (scanf("%lf", &hours) == 1 && hours != -1)
    {
        if (hours < 0) return 1;
        printf("Enter hourly rate of the worker: ");
        if (scanf("%lf", &rate) != 1 || rate < 0) return 1;
        if (hours <= 40)
            salary = hours * rate;
        else
            salary = 40 * rate + (hours - 40) * rate * 1.5;
        printf("Salary is $%.2f\n\n", salary);
        printf("Enter # of hours worked (-1 to end): ");
    }
    return 0;
}
