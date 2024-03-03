#include <stdio.h>

int main() {
    int days;
    printf("Enter the number of days: ");
    scanf("%d", &days);

    int years = days/365;
    int months = (days%365)/30;
    int r_days = days % 365 % 30;

    printf("years: %d, months: %d, days: %d", years,months,r_days);
return 0;
}