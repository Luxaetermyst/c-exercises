/*
Problem:

    Let f(i, j) be the sum of all positive divisors that i and j have in common.
    For example, f(8, 12) = 1 + 2 + 4 = 7.
    Calculate the sum of f(i, j) over all 1 <= i <= j <= n, modulo 10^9 + 7.
    Input
        One line: an integer n (1 <= n <= 10^14)
    Output
        One line: the result modulo 10^9 + 7.
Solution:
    - A common divisor e of i and j contributes e to f(i, j), so we count each e separately.
    - For a fixed e, let p = floor(n / e). The pairs i <= j <= n with both divisible by e
      number p * (p + 1) / 2.
    - Answer = sum over e = 1..n of e * p * (p + 1) / 2, where p = floor(n / e).
    - floor(n / e) takes only O(sqrt(n)) distinct values, so group e into blocks [i, k]
      with the same p, where k = n / p.
    - Sum of e in a block = (k - i + 1) * (k + i) / 2.
    - Divide by 2 before taking the modulo so that no truncation or overflow happens.
Complexity:
    - Time: O(sqrt(n)).
    - Space: O(1).
*/
#include <stdio.h>
int main(){
    long long n, sum = 0, i = 1, MOD = 1000000007;
    scanf("%lld", &n);
    while(i<=n) {
        long long p = n/i;
        long long k = n/p, a,b;
        if((k+i)%2==0){
            a = (((k-i+1)%MOD)*(((k+i)/2)%MOD))%MOD;
        } else {
            a = ((k-i+1)/2)%MOD*((k+i)%MOD)%MOD;
        }
        if(p%2==0){
            b = (p/2)%MOD*((p+1)%MOD)%MOD;
        } else {
            b = p%MOD*(((p+1)/2)%MOD)%MOD;       
        }
        sum = (sum+a*b)%MOD;
        i=k+1;
    }
    printf("%lld", sum);
    return 0;
}
