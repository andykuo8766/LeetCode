#include <stdlib.h>
#include <stdio.h>

// 9. Palindrome Number
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    long y = 0;
    int tmp = x;
    while (tmp) {
        y = y * 10 + (tmp % 10);
        tmp /= 10;
    }
    return x == y;
}

int main() {

    // 9. Palindrome Number
    int x = 121;
    if(isPalindrome(x)) {
        printf("True\n");
    }
    else{
        printf("False\n");
    }

    return 0;
}
