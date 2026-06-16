#include <stdio.h>
#include <math.h>
long long karatsuba(long long x, long long y) {
    if(x < 10 || y < 10)
        return x * y;
    int n = fmax(log10(x) + 1, log10(y) + 1);
    int m = n / 2;
    long long power = pow(10, m);
    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long adbc = karatsuba(a + b, c + d) - ac - bd;
    return ac * pow(10, 2 * m)
           + adbc * power
           + bd;
}
int main() {
    long long x, y;
    printf("Enter x and y: ");
    scanf("%lld %lld", &x, &y);
    printf("Product = %lld\n", karatsuba(x, y));
    return 0;
}