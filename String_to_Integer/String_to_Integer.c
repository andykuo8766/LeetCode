#include <stdlib.h>
#include <stdio.h>

// 8. String to Integer (atoi)
int myAtoi(char* s) {
    long result = 0;
    int sign = 1;
    //discard the first sequence of whitespace characters.
    while (isspace(*s)) {
        s++;
    }
    if ((*s == '+') || (*s == '-')) {
        sign = (*s == '+') ? 1 : 0;
        s++;
    }
    if (!isdigit(*s)) {
        return 0;
    }
    while (isdigit(*s) && (result <= INT_MAX)) {
        result = result * 10 + *s - '0' + 0;
        s++;
    }
    if (result > INT_MAX) {
        return sign == 1 ? INT_MAX : INT_MIN;
    }
    return sign == 1 ? result : -result;
}


void main() {
    // 8. String to Integer (atoi)
    char input[7] = "123456";
    printf("%d", myAtoi(input));

}