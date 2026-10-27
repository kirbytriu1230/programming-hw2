#include <stdio.h>

int main(void)
{
    int account;
    double beginning, charges, credits, limit, balance;

    printf("Enter account number (-1 to end): ");
    while (scanf("%d", &account) == 1 && account != -1)
    {
        printf("Enter beginning balance: ");
        if (scanf("%lf", &beginning) != 1) return 1;
        printf("Enter total charges: ");
        if (scanf("%lf", &charges) != 1) return 1;
        printf("Enter total credits: ");
        if (scanf("%lf", &credits) != 1) return 1;
        printf("Enter credit limit: ");
        if (scanf("%lf", &limit) != 1) return 1;

        balance = beginning + charges - credits;
        if (balance > limit)
        {
            printf("Account: %d\n", account);
            printf("Credit limit: %.2f\n", limit);
            printf("Balance: %.2f\n", balance);
            puts("Credit limit exceeded.");
        }
        printf("\nEnter account number (-1 to end): ");
    }
    return 0;
}
