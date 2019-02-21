#include <cstdio>
#include <cstdint>

int64_t power(int64_t x, int64_t n) {
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n & 1) return x*power(x*x, (n-1)/2);
    return power(x*x, n/2);
}

int main(void) {
    printf("%I64d^%I64d = %I64d\n", 2, 31, power(2LL, 31LL));
    printf("%I64d^%I64d = %I64d\n", 5, 15, power(5LL, 15LL));
    return 0;
}