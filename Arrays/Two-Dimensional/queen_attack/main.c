/*
Problem:
    Given a chess board N x N on which there are X queens being placed in X different cells. 
    Write a program that check if there are two queen, that attacks each other.

    A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.
    Input
        Line 1: contains a positive integer T which is the number of test-cases (1 <= T <= 100)
        T following block, each block is the input of a test-case with the format:
            Line 1: contains a positive integer N (1 <= N <= 100)
            Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
    Output
        In each line t (t = 1, 2, ..., T), write 1 if in the test-case t, there are no two queen that attack each other, and write 0, otherwise 
Solution:
    - Iterate over every cell that contains a queen and check its diagonals, row and column..
    - Diagonals: move along each direction until leaving the board; if another queen is found, return 0.
    - Row/column: count the queens; if there are 2 or more, return 0.
    - If no conflict is found, return 1.
Complexity:
    - Time: O(N^2) per test case.
    - Space: O(N^2).
*/
#include <stdio.h>
int text(int N,int chess[N][N]) {
    int dx[4] = {-1,-1,1,1};
    int dy[4] = {-1,1,-1,1};
    for (int i = 0; i<N; i++){
        for (int j = 0; j < N; j++){
            if (chess[i][j] == 1){
                for (int d = 0; d<4; d++){
                    int x = i+dx[d], y = j+dy[d];
                    while(x >= 0 && x < N && y >= 0 && y < N){
                        if (chess[x][y]==1){
                            return 0;
                        }
                        x += dx[d];
                        y += dy[d];
                    }
                }
                int a = 0;
                for (int k = 0; k<N; k++){
                    if(chess[i][k] == 1){
                        a++;
                    }
                    if(a==2){
                        return 0;
                    }
                }
                int b = 0;
                for (int k = 0; k<N; k++){
                    if(chess[k][j] == 1){
                        b++;
                    }
                    if (b==2){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int inOutput(){
    int N;
    scanf ("%d", &N);
    int chess[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d",&chess[i][j]);
        }
    }
    return text(N, chess);
}
int main(){
    int T;
    scanf("%d", &T);
    int a[T];
    for (int i = 0; i<T; i++) {
        a[i] = inOutput();
    }
    for(int i = 0; i<T; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}