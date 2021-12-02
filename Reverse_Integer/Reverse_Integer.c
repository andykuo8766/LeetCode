#include <stdlib.h>
#include <stdio.h>

// 7. Reverse Integer
int reverse(int x) {
    long long output = 0;
    do
    {
        output = output * 10 + x % 10;
        x /= 10;
    } while (x);

    return (output > INT_MAX || output < INT_MIN) ? 0 : output;
}

void main() {

    // 7. Reverse Integer
    int input = 123456;
    printf("%d", reverse(input));
#endif
}