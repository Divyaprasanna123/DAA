#include <stdio.h>
#include <string.h>
int main() {
    char s[50000];
    printf("Enter string: ");
    scanf("%s", s);
    int lastIndex[256];
    for(int i = 0; i < 256; i++)
        lastIndex[i] = -1;
    int start = 0;
    int maxLen = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(lastIndex[(unsigned char)s[i]] >= start)
            start = lastIndex[(unsigned char)s[i]] + 1;
        lastIndex[(unsigned char)s[i]] = i;
        int len = i - start + 1;
        if(len > maxLen)
            maxLen = len;
    }
    printf("Length of Longest Substring = %d\n", maxLen);
    return 0;
}