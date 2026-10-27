#include <stdio.h>

int main(void)
{
    int code, items;
    double salary, hours, rate, sales;

    printf("Enter pay code (1 manager, 2 hourly, 3 commission, 4 piecework, -1 end): ");
    while (scanf("%d", &code) == 1 && code != -1)
    {
        switch (code)
        {
        case 1:
            printf("Enter fixed weekly salary: ");
            if (scanf("%lf", &salary) != 1 || salary < 0) return 1;
            break;
        case 2:
            printf("Enter hours worked and hourly rate: ");
            if (scanf("%lf %lf", &hours, &rate) != 2 || hours < 0 || rate < 0)
                return 1;
            if (hours <= 40)
                salary = hours * rate;
            else
                salary = 40 * rate + (hours - 40) * rate * 1.5;
            break;
        case 3:
            printf("Enter gross weekly sales: ");
            if (scanf("%lf", &sales) != 1 || sales < 0) return 1;
            salary = 250 + 0.057 * sales;
            break;
        case 4:
            printf("Enter number of items and pay per item: ");
            if (scanf("%d %lf", &items, &rate) != 2 || items < 0 || rate < 0)
                return 1;
            salary = items * rate;
            break;
        default:
            puts("Invalid pay code.");
            printf("Enter pay code (1-4, -1 to end): ");
            continue;
        }
        printf("Weekly pay: $%.2f\n\n", salary);
        printf("Enter pay code (1-4, -1 to end): ");
    }
    return 0;
}
