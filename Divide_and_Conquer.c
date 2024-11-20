#include <stdio.h>
#include <conio.h>
typedef struct
{
    int left;
    int right;
    int sum;
} Result;
Result css(int arr[], int l, int m, int h)
{
    int sum = 0, i;
    // Find the maximum sum on the left side
    int left_sum = -10000, left_i = m;
    for (i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            left_i = i;
        }
    }
    sum = 0;
    int right_sum = -10000, right_i = m + 1;
    for (i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            right_i = i;
        }
    }
    Result res = {left_i, right_i, left_sum + right_sum};
    return res;
}
Result maxs(int arr[], int l, int h)
{
    if (l == h)
    {
        Result res = {l, h, arr[l]};
        return res;
    }
    int m = (l + h) / 2;
    Result left_res = maxs(arr, l, m);
    Result right_res = maxs(arr, m + 1, h);
    Result cross_res = css(arr, l, m, h);
    if (left_res.sum >= right_res.sum && left_res.sum >= cross_res.sum)
        return left_res;
    else if (right_res.sum >= left_res.sum && right_res.sum >= cross_res.sum)
        return right_res;
    else
        return cross_res;
}
int main()
{
    int n, k, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    Result res = maxs(arr, 0, n - 1);
    printf("Maximum subarray:\n");
    for (k = res.left; k <= res.right; ++k)
        printf("%d ", arr[k]);
    printf("\nSum: %d\n", res.sum);
    getch();
    return 0;
}
