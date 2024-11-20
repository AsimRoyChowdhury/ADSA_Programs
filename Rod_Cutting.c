#include <stdio.h>
#include <conio.h>
#include <limits.h>
int rod_cutting(int price[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int max_profit = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            max_profit = (price[j - 1] + dp[i - j] > max_profit) ? price[j - 1] + dp[i - j] : max_profit;
        }
        dp[i] = max_profit;
    }
    return dp[n];
}
int main()
{
    int n;
    printf("Enter the length of the rod: ");
    scanf("%d", &n);
    int price[n];
    printf("Enter the prices for each length:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Price for length %d: ", i + 1);
        scanf("%d", &price[i]);
    }
    int max_profit = rod_cutting(price, n);
    printf("Maximum profit is: %d\n", max_profit);
    getch();
    return 0;
}
