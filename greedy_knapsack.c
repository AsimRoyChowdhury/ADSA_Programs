#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct
{
    int weight;
    int profit;
} Item;
float *greedy_knapsack(int n, int m, Item *arr, int *frac)
{
    int i, j;
    float pw[n], temp, *x;
    Item itemtemp;
    x = (float *)malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
    {
        pw[i] = (float)arr[i].profit / arr[i].weight;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (pw[j] < pw[j + 1])
            {
                temp = pw[j];
                pw[j] = pw[j + 1];
                pw[j + 1] = temp;
                temp = frac[j];
                frac[j] = frac[j + 1];
                frac[j + 1] = temp;
                itemtemp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = itemtemp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    for (i = 0; i < n; i++)
    {
        if (m > arr[i].weight)
        {
            x[i] = 1.0;
            m -= arr[i].weight;
        }
        else
        {
            x[i] = (float)m / arr[i].weight;
            break;
        }
    }
    return x;
}
int main()
{
    int n, i, m, *frac;
    printf("Enter total weight of the knapsack = ");
    scanf("%d", &m);
    printf("Enter the number of items = ");
    scanf("%d", &n);
    Item arr[n];
    float *x, max_profit = 0;
    frac = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        frac[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("\nEnter profit of %d element = ", i + 1);
        scanf("%d", &arr[i].profit);
        printf("Enter weight of %d element = ", i + 1);
        scanf("%d", &arr[i].weight);
    }
    x = greedy_knapsack(n, m, arr, frac);
    for (i = 0; i < n; i++)
    {
        max_profit += (x[i] * arr[i].profit);
    }
    printf("Maximum profit is = %.2f", max_profit);
    printf("\nItems inserted in the knapsack are:");
    for (i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            printf("%d ", frac[i]);
        }
    }
    free(x);
    getch();
    return 0;
}
