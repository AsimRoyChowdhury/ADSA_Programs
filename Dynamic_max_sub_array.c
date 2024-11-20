#include <stdio.h>
#include <conio.h>
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int curr_sum = arr[0], max_sum = arr[0];
    for (i = 1; i < n; i++)
    {
        if (curr_sum + arr[i] > arr[i])
        {
            curr_sum += arr[i];
        }
        else
        {
            curr_sum = arr[i];
        }
        if (max_sum < curr_sum)
            max_sum = curr_sum;
    }
    printf("The maximum sum of the subarray is: %d", max_sum);
    getch();
    return 0;
}
