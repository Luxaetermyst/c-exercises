/*
Problem:
    Given an m x n table A of integers. A person starts at any cell of column 1 and must reach
    column n (any cell). From cell (i, j) the person can move to (i, j+1), (i-1, j+1) or (i+1, j+1).
    Find a path with the minimum sum of numbers.
    Input
        Line 1: two integers m, n (1 <= m, n <= 100)
        m following lines: the i-th line contains the n numbers of row i (|a[i][j]| <= 100)
    Output
        One line: the minimum sum.
Solution:
    - Dynamic programming over columns, updating the table in place:
      a[i][j] = minimum sum of a path ending at cell (i, j).
    - Column 1 keeps its own values.
    - Column j: a[i][j] += min(a[i-1][j-1], a[i][j-1], a[i+1][j-1]) (valid rows only).
    - If m == 1, the only path is the whole row, so the answer is its sum.
    - The answer is the minimum of the last column.
Complexity:
    - Time: O(m * n).
    - Space: O(m * n).
*/
#include <stdio.h>

int min3(int a, int b, int c) {
    if(a<=b) {
        if (a<=c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b<=c) {
            return b;
        } else {
            return c;
        }
    }

}
int min2(int a, int b) {
    if(a<=b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int m, n;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    if (m==1){
        int min = 0;
        for (int j =0; j<n; j++) {
            min += a[0][j];
        }
        printf("%d\n",min);
    } else {
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if (i==0) {
                    a[i][j] += min2(a[i][j-1], a[i+1][j-1]);
                } else if (i == m-1) {
                    a[i][j] += min2(a[i][j-1], a[i-1][j-1]);
                } else {
                    a[i][j] += min3(a[i][j-1], a[i-1][j-1], a[i+1][j-1]);
                }
            }
        }
        int min =a[0][n-1];
        for (int i =0; i<m; i++) {
            if (a[i][n-1]<min){
                min = a[i][n-1];
            }
        }
        printf("%d\n", min);
    }
    return 0;
}