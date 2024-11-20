#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#define N 10
int board[N][N], num_solution = 0;
bool is_safe(int board[N][N], int row, int col, int n)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j])
            return false;
    }
    return true;
}
bool n_queens(int board[N][N], int row, int n)
{
    int i, col, j;
    if (row == n)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%c ", board[i][j] ? 'Q' : '.');
            }
            printf("\n");
        }
        printf("\n");
        num_solution += 1;
        return true;
    }
    bool has_solution = false;
    for (col = 0; col < n; col++)
    {
        if (is_safe(board, row, col, n))
        {
            board[row][col] = 1;
            has_solution = n_queens(board, row + 1, n) || has_solution;
            board[row][col] = 0;
        }
    }
    return has_solution;
}
int main()
{
    int n;
    printf("Enter the number of queens(less than 10): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    if (!n_queens(board, 0, n))
    {
        printf("No solution exists\n");
    }
    else
    {
        printf("Number of Solutions = %d", num_solution);
    }
    getch();
    return 0;
}