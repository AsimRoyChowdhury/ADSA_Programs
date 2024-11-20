#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to calculate the minimum cost of matrix multiplication
void matrixChainOrder(int p[], int n, int m[MAX][MAX], int s[MAX][MAX]) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0; // Cost is zero when multiplying one matrix
    }

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Initialize to maximum value
            for (int k = i; k < j; k++) {
                // q is the cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[MAX][MAX], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int p[MAX], m[MAX][MAX], s[MAX][MAX];
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions of matrices (p[0] to p[n]): \n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n, m, s);

    printf("Minimum number of multiplications is: %d\n", m[1][n]);
    
    printf("Optimal Parenthesization is: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");

    return 0;
}