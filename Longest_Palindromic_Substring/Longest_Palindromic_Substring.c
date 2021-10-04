#include <stdlib.h>
#include <stdio.h>

//5. Longest Palindromic Substring
char* longestPalindrome(char* s) {
    char* start;
    char* end;
    char* p = s;
    char* new_start = s;
    int maxLen = 1;

    while (*p) {
        start = p; end = p;

        while (*(end + 1) && *(end + 1) == *end) {
            end++; 
        }
        p = end + 1;

        while (*(end + 1) && (start > s) && *(end + 1) == *(start - 1)) {
            start--;
            end++;
        }

        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            new_start = start;
        }
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, new_start, maxLen);
    result[maxLen] = '\0';
    return result;
}


void main() {

    //5. Longest Palindromic Substring
    int input_size = 17;
    char* input = (char*)malloc(sizeof(char) * input_size);
    input = "forgeeksskeegfor";


    printf("%s",longestPalindrome(input));

}