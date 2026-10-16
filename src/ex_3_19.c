#include <stdio.h>

int main(void)
{
    double principal, rate, interest;
    int days;

    printf("Enter loan principal (-1 to end): ");
    while (scanf("%lf", &principal) == 1 && principal != -1)
    {
        if (principal < 0) return 1;
        printf("Enter interest rate: ");
        if (scanf("%lf", &rate) != 1 || rate < 0) return 1;
        printf("Enter term of the loan in days: ");
        if (scanf("%d", &days) != 1 || days < 0) return 1;
        interest = principal * rate * days / 365;
        printf("The interest charge is $%.2f\n\n", interest);
        printf("Enter loan principal (-1 to end): ");
    }
    return 0;
}
