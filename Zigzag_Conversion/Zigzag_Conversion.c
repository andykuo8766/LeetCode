#include <stdlib.h>
#include <stdio.h>

// 6. Zigzag Conversion
char* convert(char* s, int numRows) {
    int n = strlen(s);
    char* a = (char*)malloc(sizeof(char) * (n+1));
    int k = 0;
    if (numRows == 1 || n <= numRows)return s;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < n; j += 2 * (numRows - 1))
        {
            a[k++] = s[j];
            if (i != 0 && i != numRows - 1)
            {
                int t = j + 2 * (numRows - 1) - 2 * i;
                if (t < n)
                    a[k++] = s[t];
            }
        }
    }
    a[k] = '\0';
    return a;
}


void main() {

    // 6. Zigzag Conversion
    char* s = (char*)malloc(sizeof(char) * 12);
    s = "ABCDEFGHIJK";
    printf("%s\n", convert(s,3));
    printf("%s\n", convert(s,4));

}